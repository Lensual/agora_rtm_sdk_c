#ifndef C_I_AGORA_RTM_CLIENT_H
#define C_I_AGORA_RTM_CLIENT_H

#include <stdint.h>
#include <stdbool.h>
#include "C_IAgoraStreamChannel.h"
#include "C_IAgoraRtmStorage.h"
#include "C_IAgoraRtmPresence.h"
#include "C_IAgoraRtmLock.h"
#include "C_AgoraRtmBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtm

  typedef void C_IRtmEventHandler;

  /**
   *  Configurations for RTM Client.
   */
  struct C_RtmConfig
  {
    /**
     * The App ID of your project.
     */
    const char *appId;

    /**
     * The ID of the user.
     */
    const char *userId;

    /**
     * The region for connection. This advanced feature applies to scenarios that
     * have regional restrictions.
     *
     * For the regions that Agora supports, see #AREA_CODE.
     *
     * After specifying the region, the SDK connects to the Agora servers within
     * that region.
     */
    enum C_RTM_AREA_CODE areaCode;

    /**
     * Presence timeout in seconds, specify the timeout value when you lost connection between sdk
     * and rtm service.
     */
    uint32_t presenceTimeout;

    /**
     * - For Android, it is the context of Activity or Application.
     * - For Windows, it is the window handle of app. Once set, this parameter enables you to plug
     * or unplug the video devices while they are powered.
     */
    void *context;

    /**
     * Whether to use String user IDs, if you are using RTC products with Int user IDs,
     * set this value as 'false'. Otherwise errors might occur.
     */
    bool useStringUserId;

    /**
     * The callbacks handler
     */
    C_IRtmEventHandler *eventHandler;

    /**
     * The config for customer set log path, log size and log level.
     */
    struct C_RtmLogConfig logConfig;

    /**
     * The config for proxy setting
     */
    struct C_RtmProxyConfig proxyConfig;

    /**
     * The config for encryption setting
     */
    struct C_RtmEncryptionConfig encryptionConfig;
  };
  struct C_RtmConfig *C_RtmConfig_New();
  void C_RtmConfig_Delete(struct C_RtmConfig *this_);

/**
 * The IRtmEventHandler class.
 *
 * The SDK uses this class to send callback event notifications to the app, and the app inherits
 * the methods in this class to retrieve these event notifications.
 *
 * All methods in this class have their default (empty)  implementations, and the app can inherit
 * only some of the required events instead of all. In the callback methods, the app should avoid
 * time-consuming tasks or calling blocking APIs, otherwise the SDK may not work properly.
 */
#pragma region C_IRtmEventHandler
  struct C_MessageEvent
  {
    /**
     * Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE
     */
    enum C_RTM_CHANNEL_TYPE channelType;
    /**
     * Message type
     */
    enum C_RTM_MESSAGE_TYPE messageType;
    /**
     * The channel which the message was published
     */
    const char *channelName;
    /**
     * If the channelType is RTM_CHANNEL_TYPE_STREAM, which topic the message came from. only for RTM_CHANNEL_TYPE_STREAM
     */
    const char *channelTopic;
    /**
     * The payload
     */
    const char *message;
    /**
     * The payload length
     */
    size_t messageLength;
    /**
     * The publisher
     */
    const char *publisher;
    /**
     * The custom type of the message
     */
    const char *customType;
  };
  struct C_MessageEvent *C_MessageEvent_New();
  void C_MessageEvent_Delete(struct C_MessageEvent *this_);

  struct C_IntervalInfo
  {
    /**
     * Joined users during this interval
     */
    struct C_UserList joinUserList;
    /**
     * Left users during this interval
     */
    struct C_UserList leaveUserList;
    /**
     * Timeout users during this interval
     */
    struct C_UserList timeoutUserList;
    /**
     * The user state changed during this interval
     */
    struct C_UserState *userStateList;
    /**
     * The user count
     */
    size_t userStateCount;
  };
  struct C_IntervalInfo *C_IntervalInfo_New();
  void C_IntervalInfo_Delete(struct C_IntervalInfo *this_);

  struct C_SnapshotInfo
  {
    /**
     * The user state in this snapshot event
     */
    struct C_UserState *userStateList;
    /**
     * The user count
     */
    size_t userCount;
  };
  struct C_SnapshotInfo *C_SnapshotInfo_New();
  void C_SnapshotInfo_Delete(struct C_SnapshotInfo *this_);

  struct C_PresenceEvent
  {
    /**
     * Indicate presence event type
     */
    enum C_RTM_PRESENCE_EVENT_TYPE type;
    /**
     * Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE
     */
    enum C_RTM_CHANNEL_TYPE channelType;
    /**
     * The channel which the presence event was triggered
     */
    const char *channelName;
    /**
     * The user who triggered this event.
     */
    const char *publisher;
    /**
     * The user states
     */
    const struct C_StateItem *stateItems;
    /**
     * The states count
     */
    size_t stateItemCount;
    /**
     * Only valid when in interval mode
     */
    struct C_IntervalInfo interval;
    /**
     * Only valid when receive snapshot event
     */
    struct C_SnapshotInfo snapshot;
  };
  struct C_PresenceEvent *C_PresenceEvent_New();
  void C_PresenceEvent_Delete(struct C_PresenceEvent *this_);

  struct C_TopicEvent
  {
    /**
     * Indicate topic event type
     */
    enum C_RTM_TOPIC_EVENT_TYPE type;
    /**
     * The channel which the topic event was triggered
     */
    const char *channelName;
    /**
     * The user who triggered this event.
     */
    const char *publisher;
    /**
     * Topic information array.
     */
    const struct C_TopicInfo *topicInfos;
    /**
     * The count of topicInfos.
     */
    size_t topicInfoCount;
  };
  struct C_TopicEvent *C_TopicEvent_New();
  void C_TopicEvent_Delete(struct C_TopicEvent *this_);

  struct C_LockEvent
  {
    /**
     * Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE
     */
    enum C_RTM_CHANNEL_TYPE channelType;
    /**
     * Lock event type, indicate lock states
     */
    enum C_RTM_LOCK_EVENT_TYPE eventType;
    /**
     * The channel which the lock event was triggered
     */
    const char *channelName;
    /**
     * The detail information of locks
     */
    const struct C_LockDetail *lockDetailList;
    /**
     * The count of locks
     */
    size_t count;
  };
  struct C_LockEvent *C_LockEvent_New();
  void C_LockEvent_Delete(struct C_LockEvent *this_);

  struct C_StorageEvent
  {
    /**
     * Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE
     */
    enum C_RTM_CHANNEL_TYPE channelType;
    /**
     * Storage type, RTM_STORAGE_TYPE_USER or RTM_STORAGE_TYPE_CHANNEL
     */
    enum C_RTM_STORAGE_TYPE storageType;
    /**
     * Indicate storage event type
     */
    enum C_RTM_STORAGE_EVENT_TYPE eventType;
    /**
     * The target name of user or channel, depends on the RTM_STORAGE_TYPE
     */
    const char *target;
    /**
     * The metadata information
     */
    C_IMetadata *data;
  };
  struct C_StorageEvent *C_StorageEvent_New();
  void C_StorageEvent_Delete(struct C_StorageEvent *this_);

  /**
   * Occurs when receive a message.
   *
   * @param event details of message event.
   */
  void C_IRtmEventHandler_onMessageEvent(C_IRtmEventHandler *this_, const struct C_MessageEvent *event);

  /**
   * Occurs when remote user presence changed
   *
   * @param event details of presence event.
   */
  void C_IRtmEventHandler_onPresenceEvent(C_IRtmEventHandler *this_, const struct C_PresenceEvent *event);

  /**
   * Occurs when remote user join/leave topic or when user first join this channel,
   * got snapshot of topics in this channel
   *
   * @param event details of topic event.
   */
  void C_IRtmEventHandler_onTopicEvent(C_IRtmEventHandler *this_, const struct C_TopicEvent *event);

  /**
   * Occurs when lock state changed
   *
   * @param event details of lock event.
   */
  void C_IRtmEventHandler_onLockEvent(C_IRtmEventHandler *this_, const struct C_LockEvent *event);

  /**
   * Occurs when receive storage event
   *
   * @param event details of storage event.
   */
  void C_IRtmEventHandler_onStorageEvent(C_IRtmEventHandler *this_, const struct C_StorageEvent *event);

  /**
   * Occurs when user join a stream channel.
   *
   * @param channelName The name of the channel.
   * @param userId The id of the user.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onJoinResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user leave a stream channel.
   *
   * @param channelName The name of the channel.
   * @param userId The id of the user.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onLeaveResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user join topic.
   *
   * @param channelName The name of the channel.
   * @param userId The id of the user.
   * @param topic The name of the topic.
   * @param meta The meta of the topic.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onJoinTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user leave topic.
   *
   * @param channelName The name of the channel.
   * @param userId The id of the user.
   * @param topic The name of the topic.
   * @param meta The meta of the topic.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onLeaveTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user subscribe topic.
   *
   * @param channelName The name of the channel.
   * @param userId The id of the user.
   * @param topic The name of the topic.
   * @param succeedUsers The subscribed users.
   * @param failedUser The failed to subscribe users.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onSubscribeTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, struct C_UserList succeedUsers, struct C_UserList failedUsers, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when the connection state changes between rtm sdk and agora service.
   *
   * @param channelName The name of the channel.
   * @param state The new connection state.
   * @param reason The reason for the connection state change.
   */
  void C_IRtmEventHandler_onConnectionStateChanged(C_IRtmEventHandler *this_, const char *channelName, enum C_RTM_CONNECTION_STATE state, enum C_RTM_CONNECTION_CHANGE_REASON reason);

  /**
   * Occurs when token will expire in 30 seconds.
   *
   * @param channelName The name of the channel.
   */
  void C_IRtmEventHandler_onTokenPrivilegeWillExpire(C_IRtmEventHandler *this_, const char *channelName);

  /**
   * Occurs when subscribe a channel
   *
   * @param channelName The name of the channel.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onSubscribeResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user publish message.
   *
   * @param requestId The related request id when user publish message
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onPublishResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user login.
   *
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onLoginResult(C_IRtmEventHandler *this_, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user setting the channel metadata
   *
   * @param requestId The related request id when user perform this operation
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onSetChannelMetadataResult(C_IRtmEventHandler *this_,
                                                     const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user updating the channel metadata
   *
   * @param requestId The related request id when user perform this operation
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onUpdateChannelMetadataResult(C_IRtmEventHandler *this_,
                                                        const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user removing the channel metadata
   *
   * @param requestId The related request id when user perform this operation
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onRemoveChannelMetadataResult(C_IRtmEventHandler *this_,
                                                        const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user try to get the channel metadata
   *
   * @param requestId The related request id when user perform this operation
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param data The result metadata of getting operation.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onGetChannelMetadataResult(C_IRtmEventHandler *this_,
                                                     const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user setting the user metadata
   *
   * @param requestId The related request id when user perform this operation
   * @param userId The id of the user.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onSetUserMetadataResult(C_IRtmEventHandler *this_,
                                                  const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user updating the user metadata
   *
   * @param requestId The related request id when user perform this operation
   * @param userId The id of the user.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onUpdateUserMetadataResult(C_IRtmEventHandler *this_,
                                                     const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user removing the user metadata
   *
   * @param requestId The related request id when user perform this operation
   * @param userId The id of the user.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onRemoveUserMetadataResult(C_IRtmEventHandler *this_,
                                                     const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user try to get the user metadata
   *
   * @param requestId The related request id when user perform this operation
   * @param userId The id of the user.
   * @param data The result metadata of getting operation.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onGetUserMetadataResult(C_IRtmEventHandler *this_,
                                                  const uint64_t requestId, const char *userId, const C_IMetadata *data, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user subscribe a user metadata
   *
   * @param userId The id of the user.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onSubscribeUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user set a lock
   *
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param lockName The name of the lock.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onSetLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user delete a lock
   *
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param lockName The name of the lock.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onRemoveLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user release a lock
   *
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param lockName The name of the lock.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onReleaseLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user acquire a lock
   *
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param lockName The name of the lock.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onAcquireLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode, const char *errorDetails);

  /**
   * Occurs when user revoke a lock
   *
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param lockName The name of the lock.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onRevokeLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when user try to get locks from the channel
   *
   * @param channelName The name of the channel.
   * @param channelType The type of the channel.
   * @param lockDetailList The details of the locks.
   * @param count The count of the locks.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onGetLocksResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_LockDetail *lockDetailList, const size_t count, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when query who joined this channel
   *
   * @param requestId The related request id when user perform this operation
   * @param userStatesList The states the users.
   * @param count The user count.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onWhoNowResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *userStateList, const size_t count, const char *nextPage, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when query who joined this channel
   *
   * @param requestId The related request id when user perform this operation
   * @param userStatesList The states the users.
   * @param count The user count.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onGetOnlineUsersResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *userStateList, const size_t count, const char *nextPage, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when query which channels the user joined
   *
   * @param requestId The related request id when user perform this operation
   * @param channels The channel informations.
   * @param count The channel count.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onWhereNowResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_ChannelInfo *channels, const size_t count, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when query which channels the user joined
   *
   * @param requestId The related request id when user perform this operation
   * @param channels The channel informations.
   * @param count The channel count.
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onGetUserChannelsResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_ChannelInfo *channels, const size_t count, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when set user presence
   *
   * @param requestId The related request id when user perform this operation
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onPresenceSetStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when delete user presence
   *
   * @param requestId The related request id when user perform this operation
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onPresenceRemoveStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode);

  /**
   * Occurs when get user presence
   *
   * @param requestId The related request id when user perform this operation
   * @param states The user states
   * @param errorCode The error code.
   */
  void C_IRtmEventHandler_onPresenceGetStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *state, enum C_RTM_ERROR_CODE errorCode);

#pragma endregion C_IRtmEventHandler

  /**
   * The IRtmClient class.
   *
   * This class provides the main methods that can be invoked by your app.
   *
   * IRtmClient is the basic interface class of the Agora RTM SDK.
   * Creating an IRtmClient object and then calling the methods of
   * this object enables you to use Agora RTM SDK's functionality.
   */
  typedef void C_IRtmClient;
#pragma region C_IRtmClient
  /**
   * Initializes the rtm client instance.
   *
   * @param [in] config The configurations for RTM Client.
   * @param [in] eventHandler .
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_initialize(C_IRtmClient *this_, const struct C_RtmConfig *config);

  /**
   * Release the rtm client instance.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_release(C_IRtmClient *this_);

  /**
   * Login the Agora RTM service. The operation result will be notified by \ref agora::rtm::IRtmEventHandler::onLoginResult callback.
   *
   * @param [in] token Token used to login RTM service.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_login(C_IRtmClient *this_, const char *token);

  /**
   * Logout the Agora RTM service. Be noticed that this method will break the rtm service including storage/lock/presence.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_logout(C_IRtmClient *this_);

  /**
   * Get the storage instance.
   *
   * @return
   * - return NULL if error occurred
   */
  C_IRtmStorage *C_IRtmClient_getStorage(C_IRtmClient *this_);

  /**
   * Get the lock instance.
   *
   * @return
   * - return NULL if error occurred
   */
  C_IRtmLock *C_IRtmClient_getLock(C_IRtmClient *this_);

  /**
   * Get the presence instance.
   *
   * @return
   * - return NULL if error occurred
   */
  C_IRtmPresence *C_IRtmClient_getPresence(C_IRtmClient *this_);

  /**
   * Renews the token. Once a token is enabled and used, it expires after a certain period of time.
   * You should generate a new token on your server, call this method to renew it.
   *
   * @param [in] token Token used renew.
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_renewToken(C_IRtmClient *this_, const char *token);

  /**
   * Publish a message in the channel.
   *
   * @param [in] channelName The name of the channel.
   * @param [in] message The content of the message.
   * @param [in] length The length of the message.
   * @param [in] option The option of the message.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_publish(C_IRtmClient *this_, const char *channelName, const char *message, const size_t length, const struct C_PublishOptions *option, uint64_t *requestId);

  /**
   * Subscribe a channel.
   *
   * @param [in] channelName The name of the channel.
   * @param [in] options The options of subscribe the channel.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_subscribe(C_IRtmClient *this_, const char *channelName, const struct C_SubscribeOptions *options, uint64_t *requestId);

  /**
   * Unsubscribe a channel.
   *
   * @param [in] channelName The name of the channel.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_unsubscribe(C_IRtmClient *this_, const char *channelName);

  /**
   * Create a stream channel instance.
   *
   * @param [in] channelName The Name of the channel.
   * @return
   * - return NULL if error occurred
   */
  C_IStreamChannel *C_IRtmClient_createStreamChannel(C_IRtmClient *this_, const char *channelName);

  /**
   * Set parameters of the sdk or engine
   *
   * @param [in] parameters The parameters in json format
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmClient_setParameters(C_IRtmClient *this_, const char *parameters);
#pragma endregion C_IRtmClient

  /**
   * Creates the rtm client object and returns the pointer.
   *
   * @return Pointer of the rtm client object.
   */
  C_IRtmClient *C_createAgoraRtmClient();

  /**
   * Convert error code to error string
   *
   * @param [in] errorCode Received error code
   * @return The error reason
   */
  const char *C_getErrorReason(int errorCode);

  /**
   * Get the version info of the Agora RTM SDK.
   *
   * @return The version info of the Agora RTM SDK.
   */
  const char *C_getVersion();

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_RTM_CLIENT_H
