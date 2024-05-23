#ifndef C_I_AGORA_RTM_PRESENCE_H
#define C_I_AGORA_RTM_PRESENCE_H

#include "C_AgoraRtmBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtm

  /**
   * The IRtmPresence class.
   *
   * This class provides the rtm presence methods that can be invoked by your app.
   */
  typedef void C_IRtmPresence;
#pragma region C_IRtmPresence
  /**
   * To query who joined this channel
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] options The query option.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmPresence_whoNow(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_PresenceOptions *options, uint64_t *requestId);

  /**
   * To query which channels the user joined
   *
   * @param [in] userId The id of the user.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmPresence_whereNow(C_IRtmPresence *this_, const char *userId, uint64_t *requestId);

  /**
   * Set user state
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] items The states item of user.
   * @param [in] count The count of states item.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmPresence_setState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_StateItem *items, size_t count, uint64_t *requestId);

  /**
   * Delete user state
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] keys The keys of state item.
   * @param [in] count The count of keys.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmPresence_removeState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char **keys, size_t count, uint64_t *requestId);

  /**
   * Get user state
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] userId The id of the user.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmPresence_getState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *userId, uint64_t *requestId);

  /**
   * To query who joined this channel
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] options The query option.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmPresence_getOnlineUsers(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_GetOnlineUsersOptions *options, uint64_t *requestId);

  /**
   * To query which channels the user joined
   *
   * @param [in] userId The id of the user.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmPresence_getUserChannels(C_IRtmPresence *this_, const char *userId, uint64_t *requestId);
#pragma endregion C_IRtmPresence

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_RTM_PRESENCE_H
