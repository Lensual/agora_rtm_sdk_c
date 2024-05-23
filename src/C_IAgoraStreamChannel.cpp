// 引入AgoraRTM SDK
#include "IAgoraStreamChannel.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraStreamChannel.h"

#pragma region agora

#pragma region agora::rtm
struct C_JoinChannelOptions *C_JoinChannelOptions_New()
{
  return (C_JoinChannelOptions *)new JoinChannelOptions();
}
void C_JoinChannelOptions_Delete(struct C_JoinChannelOptions *this_)
{
  delete (JoinChannelOptions *)this_;
}

struct C_JoinTopicOptions *C_JoinTopicOptions_New()
{
  return (C_JoinTopicOptions *)new JoinTopicOptions();
}
void C_JoinTopicOptions_Delete(struct C_JoinTopicOptions *this_)
{
  delete (JoinTopicOptions *)this_;
}

struct C_TopicOptions *C_TopicOptions_New()
{
  return (C_TopicOptions *)new TopicOptions();
}
void C_TopicOptions_Delete(struct C_TopicOptions *this_)
{
  delete (TopicOptions *)this_;
}

#pragma region C_IStreamChannel
int C_IStreamChannel_join(C_IStreamChannel *this_, const struct C_JoinChannelOptions *options, uint64_t *requestId)
{
  return ((IStreamChannel *)this_)->join(*(const JoinChannelOptions *)options, *requestId);
}

int C_IStreamChannel_renewToken(C_IStreamChannel *this_, const char *token)
{
  return ((IStreamChannel *)this_)->renewToken(token);
}

int C_IStreamChannel_leave(C_IStreamChannel *this_, uint64_t *requestId)
{
  return ((IStreamChannel *)this_)->leave(*requestId);
}

const char *C_IStreamChannel_getChannelName(C_IStreamChannel *this_)
{
  return ((IStreamChannel *)this_)->getChannelName();
}

int C_IStreamChannel_joinTopic(C_IStreamChannel *this_, const char *topic, const C_JoinTopicOptions *options, uint64_t *requestId)
{
  return ((IStreamChannel *)this_)->joinTopic(topic, *(const JoinTopicOptions *)options, *requestId);
}

int C_IStreamChannel_publishTopicMessage(C_IStreamChannel *this_, const char *topic, const char *message, size_t length, const struct C_TopicMessageOptions *option)
{
  return ((IStreamChannel *)this_)->publishTopicMessage(topic, message, length, *(const TopicMessageOptions *)option);
}

int C_IStreamChannel_leaveTopic(C_IStreamChannel *this_, const char *topic, uint64_t *requestId)
{
  return ((IStreamChannel *)this_)->leaveTopic(topic, *(uint64_t *)requestId);
}

int C_IStreamChannel_subscribeTopic(C_IStreamChannel *this_, const char *topic, const struct C_TopicOptions *options, uint64_t *requestId)
{
  return ((IStreamChannel *)this_)->subscribeTopic(topic, *(const TopicOptions *)options, *requestId);
}

int C_IStreamChannel_unsubscribeTopic(C_IStreamChannel *this_, const char *topic, const struct C_TopicOptions *options)
{
  return ((IStreamChannel *)this_)->unsubscribeTopic(topic, *(const TopicOptions *)options);
}

int C_IStreamChannel_getSubscribedUserList(C_IStreamChannel *this_, const char *topic, struct C_UserList *users)
{
  return ((IStreamChannel *)this_)->getSubscribedUserList(topic, (UserList *)users);
}

int C_IStreamChannel_release(C_IStreamChannel *this_)
{
  return ((IStreamChannel *)this_)->release();
}

#pragma endregion C_IStreamChannel

#pragma endregion agora::rtm

#pragma endregion agora
