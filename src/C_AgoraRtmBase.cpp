// 引入AgoraRTM SDK
#include "AgoraRtmBase.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_AgoraRtmBase.h"

#pragma region agora

#pragma region agora::rtm

struct C_RtmLogConfig *C_RtmLogConfig_New()
{
    return (C_RtmLogConfig *)(new RtmLogConfig());
}
void C_RtmLogConfig_Delete(struct C_RtmLogConfig *this_)
{
    delete (RtmLogConfig *)this_;
    this_ = nullptr;
}

struct C_UserList *C_UserList_New()
{
    return (C_UserList *)(new UserList());
}
void C_UserList_Delete(struct C_UserList *this_)
{
    delete (C_UserList *)this_;
    this_ = nullptr;
}

struct C_PublisherInfo *C_PublisherInfo_New()
{
    return (C_PublisherInfo *)(new PublisherInfo());
}
void C_PublisherInfo_Delete(struct C_PublisherInfo *this_)
{
    delete (PublisherInfo *)this_;
    this_ = nullptr;
}

struct C_TopicInfo *C_TopicInfo_New()
{
    return (C_TopicInfo *)(new TopicInfo());
}
void C_TopicInfo_Delete(struct C_TopicInfo *this_)
{
    delete (TopicInfo *)this_;
    this_ = nullptr;
}

struct C_StateItem *C_StateItem_New()
{
    return (C_StateItem *)(new StateItem());
}
void C_StateItem_Delete(struct C_StateItem *this_)
{
    delete (StateItem *)this_;
    this_ = nullptr;
}

struct C_LockDetail *C_LockDetail_New()
{
    return (C_LockDetail *)(new LockDetail());
}
void C_LockDetail_Delete(struct C_LockDetail *this_)
{
    delete (LockDetail *)this_;
    this_ = nullptr;
}

struct C_UserState *C_UserState_New()
{
    return (C_UserState *)(new UserState());
}
void C_UserState_Delete(struct C_UserState *this_)
{
    delete (UserState *)this_;
    this_ = nullptr;
}

struct C_SubscribeOptions *C_SubscribeOptions_New()
{
    return (C_SubscribeOptions *)(new SubscribeOptions());
}
void C_SubscribeOptions_Delete(struct C_SubscribeOptions *this_)
{
    delete (SubscribeOptions *)this_;
    this_ = nullptr;
}

struct C_ChannelInfo *C_ChannelInfo_New()
{
    return (C_ChannelInfo *)(new ChannelInfo());
}
void C_ChannelInfo_Delete(struct C_ChannelInfo *this_)
{
    delete (ChannelInfo *)this_;
    this_ = nullptr;
}

struct C_PresenceOptions *C_PresenceOptions_New()
{
    return (C_PresenceOptions *)(new PresenceOptions());
}
void C_PresenceOptions_Delete(struct C_PresenceOptions *this_)
{
    delete (PresenceOptions *)this_;
    this_ = nullptr;
}

struct C_GetOnlineUsersOptions *C_GetOnlineUsersOptions_New()
{
    return (C_GetOnlineUsersOptions *)(new GetOnlineUsersOptions());
}
void C_GetOnlineUsersOptions_Delete(struct C_GetOnlineUsersOptions *this_)
{
    delete (GetOnlineUsersOptions *)this_;
    this_ = nullptr;
}

struct C_PublishOptions *C_PublishOptions_New()
{
    return (C_PublishOptions *)(new PublishOptions());
}
void C_PublishOptions_Delete(struct C_PublishOptions *this_)
{
    delete (PublishOptions *)this_;
    this_ = nullptr;
}

struct C_TopicMessageOptions *C_TopicMessageOptions_New()
{
    return (C_TopicMessageOptions *)(new TopicMessageOptions());
}
void C_TopicMessageOptions_Delete(struct C_TopicMessageOptions *this_)
{
    delete (TopicMessageOptions *)this_;
    this_ = nullptr;
}

struct C_RtmProxyConfig *C_RtmProxyConfig_New()
{
    return (C_RtmProxyConfig *)(new RtmProxyConfig());
}
void C_RtmProxyConfig_Delete(struct C_RtmProxyConfig *this_)
{
    delete (RtmProxyConfig *)this_;
    this_ = nullptr;
}

struct C_RtmEncryptionConfig *C_RtmEncryptionConfig_New()
{
    return (C_RtmEncryptionConfig *)(new RtmEncryptionConfig());
}
void C_RtmEncryptionConfig_Delete(struct C_RtmEncryptionConfig *this_)
{
    delete (RtmEncryptionConfig *)this_;
    this_ = nullptr;
}

#pragma endregion agora::rtm

#pragma endregion agora