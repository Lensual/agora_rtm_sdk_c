// 引入AgoraRTM SDK
#include "IAgoraRtmService.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmService.h"

#pragma region agora

#pragma region agora::rtm

#pragma region C_IMessage
// note: undefined reference to `agora::rtm::IMessage::createMessage()'
// may be deprecated?
// C_IMessage *C_IMessage_createMessage()
// {
//   return (C_IMessage *)IMessage::createMessage();
// }
void C_IMessage_Delete(C_IMessage *this_)
{
  delete (IMessage *)this_;
}

int64_t C_IMessage_getMessageId(C_IMessage *this_)
{
  return ((IMessage *)this_)->getMessageId();
}
int C_IMessage_getMessageType(C_IMessage *this_)
{
  return ((IMessage *)this_)->getMessageType();
}
void C_IMessage_setText(C_IMessage *this_, const char *str)
{
  ((IMessage *)this_)->setText(str);
}
const char *C_IMessage_getText(C_IMessage *this_)
{
  return ((IMessage *)this_)->getText();
}
const unsigned char *C_IMessage_getRawMessageData(C_IMessage *this_)
{
  return ((IMessage *)this_)->getRawMessageData();
}
int C_IMessage_getRawMessageLength(C_IMessage *this_)
{
  return ((IMessage *)this_)->getRawMessageLength();
}
void C_IMessage_setMessageType(C_IMessage *this_, int32_t type)
{
  ((IMessage *)this_)->setMessageType(type);
}
void C_IMessage_setRawMessage(C_IMessage *this_, const uint8_t *data, int length)
{
  ((IMessage *)this_)->setRawMessage(data, length);
}
void C_IMessage_release(C_IMessage *this_)
{
  ((IMessage *)this_)->release();
}
#pragma endregion C_IMessage

#pragma region C_IChannelMember
void C_IChannelMember_Delete(C_IChannelMember *this_)
{
  delete (IChannelMember *)this_;
}
const char *C_IChannelMember_getMemberId(C_IChannelMember *this_)
{
  return ((IChannelMember *)this_)->getMemberId();
}
const char *C_IChannelMember_getChannelId(C_IChannelMember *this_)
{
  return ((IChannelMember *)this_)->getChannelId();
}
void C_IChannelMember_release(C_IChannelMember *this_)
{
  return ((IChannelMember *)this_)->release();
}
#pragma endregion C_IChannelMember

#pragma region C_IChannelAttributes
// note: undefined reference to `agora::rtm::IChannelAttributes::createChannelAttributes()'
// may be deprecated?
// C_IChannelAttributes *C_IChannelAttributes_createChannelAttributes()
// {
//   return (C_IChannelAttributes *)IChannelAttributes::createChannelAttributes();
// }
int C_IChannelAttributes_addAttribute(C_IChannelAttributes *this_, const char *key, const char *value)
{
  return ((IChannelAttributes *)this_)->addAttribute(key, value);
}
int C_IChannelAttributes_removeAttribute(C_IChannelAttributes *this_, const char *key)
{
  return ((IChannelAttributes *)this_)->removeAttribute(key);
}
int C_IChannelAttributes_getAttributesSize(C_IChannelAttributes *this_)
{
  return ((IChannelAttributes *)this_)->getAttributesSize();
}
void C_IChannelAttributes_getAttributes(C_IChannelAttributes *this_, int size, char **key,
                                        char **value)
{
  return ((IChannelAttributes *)this_)->getAttributes(size, key, value);
}
const char *C_IChannelAttributes_getAttributeValue(C_IChannelAttributes *this_, const char *key)
{
  return ((IChannelAttributes *)this_)->getAttributeValue(key);
}
int C_IChannelAttributes_release(C_IChannelAttributes *this_)
{
  return ((IChannelAttributes *)this_)->release();
}
#pragma endregion C_IChannelAttributes

#pragma region C_IChannelEventHandler
void C_IChannelEventHandler_Delete(C_IChannelEventHandler *this_)
{
  delete (IChannelEventHandler *)this_;
}
void C_IChannelEventHandler_onJoinSuccess(C_IChannelEventHandler *this_)
{
  ((IChannelEventHandler *)this_)->onJoinSuccess();
}
void C_IChannelEventHandler_onJoinFailure(C_IChannelEventHandler *this_, enum C_JOIN_CHANNEL_ERR errorCode)
{
  ((IChannelEventHandler *)this_)->onJoinFailure((JOIN_CHANNEL_ERR)errorCode);
}
void C_IChannelEventHandler_onLeave(C_IChannelEventHandler *this_, enum C_LEAVE_CHANNEL_ERR errorCode)
{
  ((IChannelEventHandler *)this_)->onLeave((LEAVE_CHANNEL_ERR)errorCode);
}
void C_IChannelEventHandler_onMessageReceived(C_IChannelEventHandler *this_, const char *userId, const C_IMessage *message)
{
  ((IChannelEventHandler *)this_)->onMessageReceived(userId, (const IMessage *)message);
}
void C_IChannelEventHandler_onSendMessageState(C_IChannelEventHandler *this_, int64_t messageId, enum C_CHANNEL_MESSAGE_STATE state)
{
  ((IChannelEventHandler *)this_)->onSendMessageState(messageId, (CHANNEL_MESSAGE_STATE)state);
}
void C_IChannelEventHandler_onSendMessageResult(C_IChannelEventHandler *this_, long long messageId, enum C_CHANNEL_MESSAGE_ERR_CODE state)
{
  ((IChannelEventHandler *)this_)->onSendMessageResult(messageId, (CHANNEL_MESSAGE_ERR_CODE)state);
}
void C_IChannelEventHandler_onMemberJoined(C_IChannelEventHandler *this_, C_IChannelMember *member)
{
  ((IChannelEventHandler *)this_)->onMemberJoined((IChannelMember *)member);
}
void C_IChannelEventHandler_onMemberLeft(C_IChannelEventHandler *this_, C_IChannelMember *member)
{
  ((IChannelEventHandler *)this_)->onMemberLeft((IChannelMember *)member);
}
void C_IChannelEventHandler_onMembersGotten(C_IChannelEventHandler *this_, C_IChannelMember **members, int userCount)
{
  ((IChannelEventHandler *)this_)->onMembersGotten((IChannelMember **)members, userCount);
}
void C_IChannelEventHandler_onAttributesUpdated(C_IChannelEventHandler *this_, const C_IChannelAttributes *attributes)
{
  ((IChannelEventHandler *)this_)->onAttributesUpdated((const IChannelAttributes *)attributes);
}
void C_IChannelEventHandler_onUpdateAttributesResponse(C_IChannelEventHandler *this_, int64_t requestId, enum C_RESPONSE_CODE resCode)
{
  ((IChannelEventHandler *)this_)->onUpdateAttributesResponse(requestId, (RESPONSE_CODE)resCode);
}
void C_IChannelEventHandler_onAttributesDeleted(C_IChannelEventHandler *this_, const C_IChannelAttributes *attributes)
{
  ((IChannelEventHandler *)this_)->onAttributesDeleted((const IChannelAttributes *)attributes);
}
void C_IChannelEventHandler_onDeleteAttributesResponse(C_IChannelEventHandler *this_, int64_t requestId, enum C_RESPONSE_CODE resCode)
{
  ((IChannelEventHandler *)this_)->onDeleteAttributesResponse(requestId, (RESPONSE_CODE)resCode);
}
#pragma endregion C_IChannelEventHandler

#pragma region C_IChannel
void C_IChannel_setEventHandler(C_IChannel *this_, C_IChannelEventHandler *eventHandler)
{
  ((IChannel *)this_)->setEventHandler((IChannelEventHandler *)eventHandler);
}
int C_IChannel_join(C_IChannel *this_)
{
  return ((IChannel *)this_)->join();
}
int C_IChannel_leave(C_IChannel *this_)
{
  return ((IChannel *)this_)->leave();
}
int C_IChannel_sendMessage(C_IChannel *this_, const C_IMessage *message)
{
  return ((IChannel *)this_)->sendMessage((const IMessage *)message);
}
int C_IChannel_updateAttributes(C_IChannel *this_, C_IChannelAttributes *attributes, int64_t *requestId)
{
  return ((IChannel *)this_)->updateAttributes((IChannelAttributes *)attributes, *requestId);
}
int C_IChannel_deleteAttributes(C_IChannel *this_, C_IChannelAttributes *attributes, int64_t *requestId)
{
  return ((IChannel *)this_)->deleteAttributes((IChannelAttributes *)attributes, *requestId);
}
const char *C_IChannel_getId(C_IChannel *this_)
{
  return ((IChannel *)this_)->getId();
}

int C_IChannel_release(C_IChannel *this_)
{
  return ((IChannel *)this_)->release();
}
#pragma endregion C_IChannel

#pragma region C_IRtmServiceEventHandler
void C_IRtmServiceEventHandler_Delete(C_IRtmServiceEventHandler *this_)
{
  delete (IRtmServiceEventHandler *)this_;
}
void C_IRtmServiceEventHandler_onLoginSuccess(C_IRtmServiceEventHandler *this_)
{
  ((IRtmServiceEventHandler *)this_)->onLoginSuccess();
}
void C_IRtmServiceEventHandler_onLoginFailure(C_IRtmServiceEventHandler *this_, enum C_LOGIN_ERR_CODE errorCode)
{
  ((IRtmServiceEventHandler *)this_)->onLoginFailure((LOGIN_ERR_CODE)errorCode);
}
void C_IRtmServiceEventHandler_onLogout(C_IRtmServiceEventHandler *this_)
{
  ((IRtmServiceEventHandler *)this_)->onLogout();
}
void C_IRtmServiceEventHandler_onConnectionStateChanged(C_IRtmServiceEventHandler *this_, enum C_CONNECTION_STATE state)
{
  ((IRtmServiceEventHandler *)this_)->onConnectionStateChanged((CONNECTION_STATE)state);
}
void C_IRtmServiceEventHandler_onSendMessageState(C_IRtmServiceEventHandler *this_, int64_t messageId, enum C_PEER_MESSAGE_STATE state)
{
  ((IRtmServiceEventHandler *)this_)->onSendMessageState(messageId, (PEER_MESSAGE_STATE)state);
}
void C_IRtmServiceEventHandler_onMessageReceivedFromPeer(IRtmServiceEventHandler *this_, const char *peerId, const C_IMessage *message)
{
  ((IRtmServiceEventHandler *)this_)->onMessageReceivedFromPeer(peerId, (const IMessage *)message);
}
#pragma endregion C_IRtmServiceEventHandler

#pragma region C_IRtmService
void C_IRtmService_Delete(C_IRtmService *this_)
{
  delete (IRtmService *)this_;
}
int C_IRtmService_initialize(C_IRtmService *this_, const char *appId, C_IRtmServiceEventHandler *eventHandler)
{
  return ((IRtmService *)this_)->initialize(appId, (IRtmServiceEventHandler *)eventHandler);
}
void C_IRtmService_unregisterObserver(C_IRtmService *this_, C_IRtmServiceEventHandler *eventHandler)
{
  ((IRtmService *)this_)->unregisterObserver((IRtmServiceEventHandler *)eventHandler);
}
int C_IRtmService_release(C_IRtmService *this_, bool sync)
{
  return ((IRtmService *)this_)->release();
}
int C_IRtmService_login(C_IRtmService *this_, const char *token, const char *userId)
{
  return ((IRtmService *)this_)->login(token, userId);
}
int C_IRtmService_logout(C_IRtmService *this_)
{
  return ((IRtmService *)this_)->logout();
}
int C_IRtmService_sendMessageToPeer(C_IRtmService *this_, const char *peerId, const C_IMessage *message)
{
  return ((IRtmService *)this_)->sendMessageToPeer(peerId, (const IMessage *)message);
}
C_IChannel *C_IRtmService_createChannel(C_IRtmService *this_, const char *channelId, C_IChannelEventHandler *eventHandler)
{
  return (C_IChannel *)((IRtmService *)this_)->createChannel(channelId, (IChannelEventHandler *)eventHandler);
}
#pragma endregion C_IRtmService

#pragma endregion agora::rtm

#pragma endregion agora
