// 引入AgoraRTM SDK
#include "IAgoraRtmPresence.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmPresence.h"

#pragma region agora

#pragma region agora::rtm

#pragma region C_IRtmPresence

int C_IRtmPresence_whoNow(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_PresenceOptions *options, uint64_t *requestId)
{
    return ((IRtmPresence *)this_)->whoNow(channelName, (RTM_CHANNEL_TYPE)channelType, *(const PresenceOptions *)options, *requestId);
}

int C_IRtmPresence_whereNow(C_IRtmPresence *this_, const char *userId, uint64_t *requestId)
{
    return ((IRtmPresence *)this_)->whereNow(userId, *requestId);
}

int C_IRtmPresence_setState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_StateItem *items, size_t count, uint64_t *requestId)
{
    return ((IRtmPresence *)this_)->setState(channelName, (RTM_CHANNEL_TYPE)channelType, (const StateItem *)items, count, *requestId);
}

int C_IRtmPresence_removeState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char **keys, size_t count, uint64_t *requestId)
{
    return ((IRtmPresence *)this_)->removeState(channelName, (RTM_CHANNEL_TYPE)channelType, keys, count, *requestId);
}

int C_IRtmPresence_getState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *userId, uint64_t *requestId)
{
    return ((IRtmPresence *)this_)->getState(channelName, (RTM_CHANNEL_TYPE)channelType, userId, *requestId);
}

int C_IRtmPresence_getOnlineUsers(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_GetOnlineUsersOptions *options, uint64_t *requestId)
{
    return ((IRtmPresence *)this_)->getOnlineUsers(channelName, (RTM_CHANNEL_TYPE)channelType, *(const GetOnlineUsersOptions *)options, *requestId);
}

int C_IRtmPresence_getUserChannels(C_IRtmPresence *this_, const char *userId, uint64_t *requestId)
{
    return ((IRtmPresence *)this_)->getUserChannels(userId, *requestId);
}
#pragma endregion C_IRtmPresence

#pragma endregion agora::rtm

#pragma endregion agora
