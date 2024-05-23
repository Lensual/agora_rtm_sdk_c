#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "C_IAgoraRtmClient.h"

#include "bridge/C_RtmEventHandlerBridge.h"

// Pass in your App ID here
const char *APP_ID = "<Your App ID>";
const char *TOKEN = "<Token From Agora Console>";

// Terminal color codes for UBUNTU/LINUX
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

// using namespace agora::rtm;

void C_DemoRtmEventHandler_cbPrint(const char *fmt, ...)
{
    printf("\x1b[32m<< RTM async callback: ");
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf(" >>\x1b[0m\n");
}

void C_DemoRtmEventHandler_onLoginResult(C_RtmEventHandlerBridge *this_, void *userData, enum C_RTM_ERROR_CODE errorCode)
{
    C_DemoRtmEventHandler_cbPrint("onLogin: errorCode: %d", errorCode);
}
void C_DemoRtmEventHandler_onConnectionStateChanged(C_RtmEventHandlerBridge *this_, void *userData, const char *channelName, enum C_RTM_CONNECTION_STATE state, enum C_RTM_CONNECTION_CHANGE_REASON reason)
{
    C_DemoRtmEventHandler_cbPrint("onConnectionStateChanged: %d", state);
}
void C_DemoRtmEventHandler_onPublishResult(C_RtmEventHandlerBridge *this_, void *userData, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    C_DemoRtmEventHandler_cbPrint("onPublishResult request id: %lld result: %d", requestId, errorCode);
}
void C_DemoRtmEventHandler_onMessageEvent(C_RtmEventHandlerBridge *this_, void *userData, const struct C_MessageEvent *event)
{
    C_DemoRtmEventHandler_cbPrint("receive message from: %s, message: %s", event->publisher, event->message);
}
void C_DemoRtmEventHandler_onSubscribeResult(C_RtmEventHandlerBridge *this_, void *userData, const uint64_t requestId, const char *channelName, enum C_RTM_ERROR_CODE errorCode)
{
    C_DemoRtmEventHandler_cbPrint("onSubscribeResult: channel:%s, request id: %lld result: %d", channelName, requestId, errorCode);
}

// Add the event listener
C_RtmEventHandlerBridge_Callbacks C_DemoRtmEventHandler = {
    .onLoginResult = C_DemoRtmEventHandler_onLoginResult,
    .onConnectionStateChanged = C_DemoRtmEventHandler_onConnectionStateChanged,
    .onPublishResult = C_DemoRtmEventHandler_onPublishResult,
    .onMessageEvent = C_DemoRtmEventHandler_onMessageEvent,
    .onSubscribeResult = C_DemoRtmEventHandler_onSubscribeResult,
};

typedef struct C_DemoMessaging
{
    C_RtmEventHandlerBridge *eventHandler_;
    C_IRtmClient *rtmClient_;
} C_DemoMessaging;
#pragma region C_DemoMessaging

C_DemoMessaging *C_DemoMessaging_New()
{
    C_DemoMessaging *this_ = (C_DemoMessaging *)malloc(sizeof(C_DemoMessaging));
    this_->eventHandler_ = C_RtmEventHandlerBridge_New(C_DemoRtmEventHandler, NULL);

    // Create an IRtmClient instance
    this_->rtmClient_ = C_createAgoraRtmClient();
    if (!this_->rtmClient_)
    {
        printf(RED "error creating rtm service!\n" RESET);
        exit(0);
    }

    return this_;
}

// Log out from the RTM server
void C_DemoMessaging_logout(C_DemoMessaging *this_)
{
    int ret = C_IRtmClient_logout(this_->rtmClient_);
    printf(BOLDBLUE "logout ret: %d\n", ret);
}

// Subscribe to a channel
void C_DemoMessaging_subscribeChannel(C_DemoMessaging *this_, char *chnId)
{
    struct C_SubscribeOptions *opt = C_SubscribeOptions_New();
    uint64_t req_id;
    int ret = C_IRtmClient_subscribe(this_->rtmClient_, chnId, opt, &req_id);
    printf(BOLDBLUE "subscribe channel ret:%d\n", ret);
}

// Unsubscribe from a channel
void C_DemoMessaging_unsubscribeChannel(C_DemoMessaging *this_, char *chnId)
{
    uint64_t req_id;
    int ret = C_IRtmClient_unsubscribe(this_->rtmClient_, chnId);
    printf(BOLDBLUE "unsubscribe channel ret:%d\n", ret);
}

// Publish a message
void C_DemoMessaging_publishMessage(C_DemoMessaging *this_, char *chn, char *msg)
{
    struct C_PublishOptions *opt = C_PublishOptions_New();
    opt->messageType = RTM_MESSAGE_TYPE_STRING;
    uint64_t req_id;
    int ret = C_IRtmClient_publish(this_->rtmClient_, chn, msg, strlen(msg), opt, &req_id);
    printf(BOLDBLUE "publishMessage ret:%d request id: %ld\n", ret, req_id);
}

void C_DemoMessaging_Chat(C_DemoMessaging *this_, char *channel)
{
    char message[33];
    while (true)
    {
        printf(YELLOW "please input message "
                      "or input \"quit\" to leave groupchat,\n");
        scanf("%32s", message);
        if (strcmp(message, "quit") == 0)
        {
            return;
        }
        else
        {
            C_DemoMessaging_publishMessage(this_, channel, message);
        }
    }
}

// Sample codes for the user interface
void C_DemoMessaging_mainMeun(C_DemoMessaging *this_)
{
    bool quit = false;
    while (!quit)
    {
        printf(WHITE "1: subcribe channel\n"
                     "2: unsubcribe channel\n"
                     "3: publish message\n"
                     "4: logout\n");
        printf(YELLOW "please input your choice\n");
        char input[2];
        scanf("%1s", input);
        int32_t choice = 0;
        if (!sscanf(input, "%d", &choice))
        {
            printf(RED "invalid input\n");
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            printf(YELLOW "please input dst channel id\n");
            char dst[65];
            scanf("%64s", dst);
            C_DemoMessaging_subscribeChannel(this_, dst);
        }
        break;
        case 2:
        {
            printf(YELLOW "please input dst channel id\n");
            char dst[65];
            scanf("%64s", dst);
            C_DemoMessaging_unsubscribeChannel(this_, dst);
        }
        break;
        case 3:
        {
            printf(YELLOW "please input channel id\n");
            char channel[65];
            scanf("%64s", channel);
            C_DemoMessaging_Chat(this_, channel);
        }
        break;
        case 4:
        {
            C_DemoMessaging_logout(this_);
            return;
        }
        break;
        default:
            break;
        }
    }
}

void C_DemoMessaging_login(C_DemoMessaging *this_)
{
    while (true)
    {
        printf(YELLOW "Please enter userID (literal \"null\" or starting"
                      "with space is not allowed, no more than 64 charaters!):"
                      "\n");

        char userID[65]; // 64个字符 + 结尾的 null 字符
        scanf("%64s", userID);

        struct C_RtmConfig *cfg = C_RtmConfig_New();
        cfg->appId = APP_ID;
        cfg->userId = userID;
        cfg->eventHandler = this_->eventHandler_;
        // Initialize an IRtmClient instance
        int ret = C_IRtmClient_initialize(this_->rtmClient_, cfg);
        // Log in the RTM server
        if (ret)
        {
            printf(RED "error initializing rtm service: %d\n", ret);
            exit(0);
        }
        ret = C_IRtmClient_login(this_->rtmClient_, TOKEN);
        printf(BOLDBLUE "login ret:%d\n", ret);
        if (ret)
        {
            C_DemoMessaging_login(this_);
        }
        // Sample codes for the user interface
        C_DemoMessaging_mainMeun(this_);
        printf(YELLOW "quit ? yes/no\n");
        char input[4];
        scanf("%3s", input);
        if (strcmp(input, "yes") == 0)
        {
            exit(0);
        }
    }
}

#pragma endregion C_DemoMessaging

int main(int argc, const char *argv[])
{
    C_DemoMessaging *messaging = C_DemoMessaging_New();
    C_DemoMessaging_login(messaging);
    return 0;
}
