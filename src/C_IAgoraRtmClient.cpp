// 引入AgoraRTM SDK
#include "IAgoraRtmClient.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmClient.h"

#pragma region agora

#pragma region agora::rtm

struct C_RtmConfig *C_RtmConfig_New()
{
    return (C_RtmConfig *)(new RtmConfig());
}
void C_RtmConfig_Delete(struct C_RtmConfig *this_)
{
    delete (RtmConfig *)(this_);
}

#pragma region C_IRtmEventHandler

struct C_MessageEvent *C_MessageEvent_New()
{
    return (C_MessageEvent *)(new agora::rtm::IRtmEventHandler::MessageEvent());
}
void C_MessageEvent_Delete(struct C_MessageEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::MessageEvent *)(this_);
}

struct C_IntervalInfo *C_IntervalInfo_New()
{
    return (C_IntervalInfo *)(new agora::rtm::IRtmEventHandler::PresenceEvent::IntervalInfo());
}
void C_IntervalInfo_Delete(struct C_IntervalInfo *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent::IntervalInfo *)(this_);
}

struct C_SnapshotInfo *C_SnapshotInfo_New()
{
    return (C_SnapshotInfo *)(new agora::rtm::IRtmEventHandler::PresenceEvent::SnapshotInfo());
}
void C_SnapshotInfo_Delete(struct C_SnapshotInfo *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent::SnapshotInfo *)(this_);
}

struct C_PresenceEvent *C_PresenceEvent_New()
{
    return (C_PresenceEvent *)(new agora::rtm::IRtmEventHandler::PresenceEvent());
}
void C_PresenceEvent_Delete(struct C_PresenceEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent *)(this_);
}

struct C_TopicEvent *C_TopicEvent_New()
{
    return (C_TopicEvent *)(new agora::rtm::IRtmEventHandler::TopicEvent());
}
void C_TopicEvent_Delete(struct C_TopicEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::TopicEvent *)(this_);
}

struct C_LockEvent *C_LockEvent_New()
{
    return (C_LockEvent *)(new agora::rtm::IRtmEventHandler::LockEvent());
}
void C_LockEvent_Delete(struct C_LockEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::LockEvent *)(this_);
}

struct C_StorageEvent *C_StorageEvent_New()
{
    return (C_StorageEvent *)(new agora::rtm::IRtmEventHandler::StorageEvent());
}
void C_StorageEvent_Delete(struct C_StorageEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::StorageEvent *)(this_);
}

void C_IRtmEventHandler_onMessageEvent(C_IRtmEventHandler *this_, const C_MessageEvent *event)
{
    ((IRtmEventHandler *)this_)->onMessageEvent(*(const IRtmEventHandler::MessageEvent *)event);
}

void C_IRtmEventHandler_onPresenceEvent(C_IRtmEventHandler *this_, const C_PresenceEvent *event)
{
    ((IRtmEventHandler *)this_)->onPresenceEvent(*(const IRtmEventHandler::PresenceEvent *)event);
}

void C_IRtmEventHandler_onTopicEvent(C_IRtmEventHandler *this_, const C_TopicEvent *event)
{
    ((IRtmEventHandler *)this_)->onTopicEvent(*(const IRtmEventHandler::TopicEvent *)event);
}

void C_IRtmEventHandler_onLockEvent(C_IRtmEventHandler *this_, const C_LockEvent *event)
{
    ((IRtmEventHandler *)this_)->onLockEvent(*(const IRtmEventHandler::LockEvent *)event);
}

void C_IRtmEventHandler_onStorageEvent(C_IRtmEventHandler *this_, const C_StorageEvent *event)
{
    ((IRtmEventHandler *)this_)->onStorageEvent(*(const IRtmEventHandler::StorageEvent *)event);
}

void C_IRtmEventHandler_onJoinResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onJoinResult(requestId, channelName, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLeaveResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLeaveResult(requestId, channelName, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onJoinTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onJoinTopicResult(requestId, channelName, userId, topic, meta, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLeaveTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLeaveTopicResult(requestId, channelName, userId, topic, meta, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSubscribeTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, struct C_UserList succeedUsers, struct C_UserList failedUsers, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeTopicResult(requestId, channelName, userId, topic, *(UserList *)&succeedUsers, *(UserList *)&failedUsers, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onConnectionStateChanged(C_IRtmEventHandler *this_, const char *channelName, enum C_RTM_CONNECTION_STATE state, enum C_RTM_CONNECTION_CHANGE_REASON reason)
{
    ((IRtmEventHandler *)this_)->onConnectionStateChanged(channelName, (RTM_CONNECTION_STATE)state, (RTM_CONNECTION_CHANGE_REASON)reason);
}

void C_IRtmEventHandler_onTokenPrivilegeWillExpire(C_IRtmEventHandler *this_, const char *channelName)
{
    ((IRtmEventHandler *)this_)->onTokenPrivilegeWillExpire(channelName);
}

void C_IRtmEventHandler_onSubscribeResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeResult(requestId, channelName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPublishResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPublishResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLoginResult(C_IRtmEventHandler *this_, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLoginResult((RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUpdateChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUpdateChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, *(const IMetadata *)data, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUpdateUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUpdateUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, const C_IMetadata *data, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetUserMetadataResult(requestId, userId, *(const IMetadata *)data, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSubscribeUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onReleaseLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onReleaseLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onAcquireLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode, const char *errorDetails)
{
    ((IRtmEventHandler *)this_)->onAcquireLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode, errorDetails);
}

void C_IRtmEventHandler_onRevokeLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRevokeLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetLocksResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_LockDetail *lockDetailList, const size_t count, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetLocksResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (const LockDetail *)lockDetailList, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onWhoNowResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *userStateList, const size_t count, const char *nextPage, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onWhoNowResult(requestId, (const UserState *)userStateList, count, nextPage, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetOnlineUsersResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *userStateList, const size_t count, const char *nextPage, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetOnlineUsersResult(requestId, (const UserState *)userStateList, count, nextPage, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onWhereNowResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_ChannelInfo *channels, const size_t count, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onWhereNowResult(requestId, (const ChannelInfo *)channels, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetUserChannelsResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_ChannelInfo *channels, const size_t count, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetUserChannelsResult(requestId, (const ChannelInfo *)channels, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceSetStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceSetStateResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceRemoveStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceRemoveStateResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceGetStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *state, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceGetStateResult(requestId, *(const UserState *)state, (RTM_ERROR_CODE)errorCode);
}

#pragma endregion C_IRtmEventHandler

#pragma region C_IRtmClient
int C_IRtmClient_initialize(C_IRtmClient *this_, const C_RtmConfig *config)
{
    return ((IRtmClient *)this_)->initialize(*(const RtmConfig *)config);
}

int C_IRtmClient_release(C_IRtmClient *this_)
{
    return ((IRtmClient *)this_)->release();
}

int C_IRtmClient_login(C_IRtmClient *this_, const char *token)
{
    return ((IRtmClient *)this_)->login(token);
}

int C_IRtmClient_logout(C_IRtmClient *this_)
{
    return ((IRtmClient *)this_)->logout();
}

C_IRtmStorage *C_IRtmClient_getStorage(C_IRtmClient *this_)
{
    return ((IRtmClient *)this_)->getStorage();
}

C_IRtmLock *C_IRtmClient_getLock(C_IRtmClient *this_)
{
    return ((IRtmClient *)this_)->getLock();
}

C_IRtmPresence *C_IRtmClient_getPresence(C_IRtmClient *this_)
{
    return ((IRtmClient *)this_)->getPresence();
}

int C_IRtmClient_renewToken(C_IRtmClient *this_, const char *token)
{
    return ((IRtmClient *)this_)->renewToken(token);
}

int C_IRtmClient_publish(C_IRtmClient *this_, const char *channelName, const char *message, const size_t length, const C_PublishOptions *option, uint64_t *requestId)
{
    return ((IRtmClient *)this_)->publish(channelName, message, length, *(const PublishOptions *)option, *requestId);
}

int C_IRtmClient_subscribe(C_IRtmClient *this_, const char *channelName, const C_SubscribeOptions *options, uint64_t *requestId)
{
    return ((IRtmClient *)this_)->subscribe(channelName, *(const SubscribeOptions *)options, *requestId);
}

int C_IRtmClient_unsubscribe(C_IRtmClient *this_, const char *channelName)
{
    return ((IRtmClient *)this_)->unsubscribe(channelName);
}

C_IStreamChannel *C_IRtmClient_createStreamChannel(C_IRtmClient *this_, const char *channelName)
{
    return ((IRtmClient *)this_)->createStreamChannel(channelName);
}

int C_IRtmClient_setParameters(C_IRtmClient *this_, const char *parameters)
{
    return ((IRtmClient *)this_)->setParameters(parameters);
}
#pragma endregion C_IRtmClient

C_IRtmClient *C_createAgoraRtmClient()
{
    return createAgoraRtmClient();
}

const char *C_getErrorReason(int errorCode)
{
    return getErrorReason(errorCode);
}

const char *C_getVersion()
{
    return getVersion();
}

#pragma endregion agora::rtm

#pragma endregion agora
