// 引入AgoraRTM SDK
#include "IAgoraRtmLock.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmLock.h"

#pragma region agora

#pragma region agora::rtm

#pragma region C_IRtmLock

int C_IRtmLock_setLock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint32_t ttl, uint64_t *requestId)
{
    return ((IRtmLock *)this_)->setLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, ttl, *requestId);
}

int C_IRtmLock_getLocks(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, uint64_t *requestId)
{
    return ((IRtmLock *)this_)->getLocks(channelName, (RTM_CHANNEL_TYPE)channelType, *requestId);
}

int C_IRtmLock_removeLock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint64_t *requestId)
{
    return ((IRtmLock *)this_)->removeLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, *requestId);
}

int C_IRtmLock_acquireLock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, bool retry, uint64_t *requestId)
{
    return ((IRtmLock *)this_)->acquireLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, retry, *requestId);
}

int C_IRtmLock_releaseLock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint64_t *requestId)
{
    return ((IRtmLock *)this_)->releaseLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, *requestId);
}

int C_IRtmLock_revokeLock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, const char *owner, uint64_t *requestId)
{
    return ((IRtmLock *)this_)->revokeLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, owner, *requestId);
}

#pragma endregion C_IRtmLock

#pragma endregion agora::rtm

#pragma endregion agora
