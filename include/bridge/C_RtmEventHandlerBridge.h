#ifndef C_RTM_EVENT_HANDLER_BRIDGE_H
#define C_RTM_EVENT_HANDLER_BRIDGE_H

#include "C_IAgoraRtmClient.h"
#include "C_IAgoraRtmStorage.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

    typedef void C_RtmEventHandlerBridge;
#pragma region C_RtmEventHandlerBridge
    // Callbacks

    /**
     * Occurs when receive a message.
     *
     * @param event details of message event.
     */
    typedef void (*C_RtmEventHandlerBridge_onMessageEvent)(C_RtmEventHandlerBridge *this_, void *userData,
                                                           const struct C_MessageEvent *event);

    /**
     * Occurs when remote user presence changed
     *
     * @param event details of presence event.
     */
    typedef void (*C_RtmEventHandlerBridge_onPresenceEvent)(C_RtmEventHandlerBridge *this_, void *userData,
                                                            const struct C_PresenceEvent *event);

    /**
     * Occurs when remote user join/leave topic or when user first join this channel,
     * got snapshot of topics in this channel
     *
     * @param event details of topic event.
     */
    typedef void (*C_RtmEventHandlerBridge_onTopicEvent)(C_RtmEventHandlerBridge *this_, void *userData,
                                                         const struct C_TopicEvent *event);

    /**
     * Occurs when lock state changed
     *
     * @param event details of lock event.
     */
    typedef void (*C_RtmEventHandlerBridge_onLockEvent)(C_RtmEventHandlerBridge *this_, void *userData,
                                                        const struct C_LockEvent *event);

    /**
     * Occurs when receive storage event
     *
     * @param event details of storage event.
     */
    typedef void (*C_RtmEventHandlerBridge_onStorageEvent)(C_RtmEventHandlerBridge *this_, void *userData,
                                                           const struct C_StorageEvent *event);

    /**
     * Occurs when user join a stream channel.
     *
     * @param channelName The name of the channel.
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onJoinResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                         const uint64_t requestId, const char *channelName, const char *userId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user leave a stream channel.
     *
     * @param channelName The name of the channel.
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onLeaveResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                          const uint64_t requestId, const char *channelName, const char *userId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user join topic.
     *
     * @param channelName The name of the channel.
     * @param userId The id of the user.
     * @param topic The name of the topic.
     * @param meta The meta of the topic.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onJoinTopicResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                              const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user leave topic.
     *
     * @param channelName The name of the channel.
     * @param userId The id of the user.
     * @param topic The name of the topic.
     * @param meta The meta of the topic.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onLeaveTopicResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                               const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, enum C_RTM_ERROR_CODE errorCode);

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
    typedef void (*C_RtmEventHandlerBridge_onSubscribeTopicResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                   const uint64_t requestId, const char *channelName, const char *userId, const char *topic, struct C_UserList succeedUsers, struct C_UserList failedUsers, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when the connection state changes between rtm sdk and agora service.
     *
     * @param channelName The name of the channel.
     * @param state The new connection state.
     * @param reason The reason for the connection state change.
     */
    typedef void (*C_RtmEventHandlerBridge_onConnectionStateChanged)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                     const char *channelName, enum C_RTM_CONNECTION_STATE state, enum C_RTM_CONNECTION_CHANGE_REASON reason);

    /**
     * Occurs when token will expire in 30 seconds.
     *
     * @param channelName The name of the channel.
     */
    typedef void (*C_RtmEventHandlerBridge_onTokenPrivilegeWillExpire)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                       const char *channelName);

    /**
     * Occurs when subscribe a channel
     *
     * @param channelName The name of the channel.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onSubscribeResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                              const uint64_t requestId, const char *channelName, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user publish message.
     *
     * @param requestId The related request id when user publish message
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onPublishResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                            const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user login.
     *
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onLoginResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                          enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user setting the channel metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onSetChannelMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                       const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user updating the channel metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onUpdateChannelMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                          const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user removing the channel metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onRemoveChannelMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
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
    typedef void (*C_RtmEventHandlerBridge_onGetChannelMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                       const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user setting the user metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onSetUserMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                    const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user updating the user metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onUpdateUserMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                       const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user removing the user metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onRemoveUserMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                       const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user try to get the user metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param userId The id of the user.
     * @param data The result metadata of getting operation.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onGetUserMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                    const uint64_t requestId, const char *userId, const C_IMetadata *data, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user subscribe a user metadata
     *
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onSubscribeUserMetadataResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                          const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user set a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onSetLockResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                            const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user delete a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onRemoveLockResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                               const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user release a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onReleaseLockResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user acquire a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onAcquireLockResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode, const char *errorDetails);

    /**
     * Occurs when user revoke a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onRevokeLockResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                               const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when user try to get locks from the channel
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockDetailList The details of the locks.
     * @param count The count of the locks.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onGetLocksResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                             const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_LockDetail *lockDetailList, const size_t count, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when query who joined this channel
     *
     * @param requestId The related request id when user perform this operation
     * @param userStatesList The states the users.
     * @param count The user count.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onWhoNowResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                           const uint64_t requestId, const struct C_UserState *userStateList, const size_t count, const char *nextPage, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when query who joined this channel
     *
     * @param requestId The related request id when user perform this operation
     * @param userStatesList The states the users.
     * @param count The user count.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onGetOnlineUsersResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                   const uint64_t requestId, const struct C_UserState *userStateList, const size_t count, const char *nextPage, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when query which channels the user joined
     *
     * @param requestId The related request id when user perform this operation
     * @param channels The channel informations.
     * @param count The channel count.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onWhereNowResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                             const uint64_t requestId, const struct C_ChannelInfo *channels, const size_t count, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when query which channels the user joined
     *
     * @param requestId The related request id when user perform this operation
     * @param channels The channel informations.
     * @param count The channel count.
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onGetUserChannelsResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                    const uint64_t requestId, const struct C_ChannelInfo *channels, const size_t count, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when set user presence
     *
     * @param requestId The related request id when user perform this operation
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onPresenceSetStateResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                     const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when delete user presence
     *
     * @param requestId The related request id when user perform this operation
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onPresenceRemoveStateResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                        const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode);

    /**
     * Occurs when get user presence
     *
     * @param requestId The related request id when user perform this operation
     * @param states The user states
     * @param errorCode The error code.
     */
    typedef void (*C_RtmEventHandlerBridge_onPresenceGetStateResult)(C_RtmEventHandlerBridge *this_, void *userData,
                                                                     const uint64_t requestId, const struct C_UserState *state, enum C_RTM_ERROR_CODE errorCode);

    typedef struct C_RtmEventHandlerBridge_Callbacks
    {
        C_RtmEventHandlerBridge_onMessageEvent onMessageEvent;
        C_RtmEventHandlerBridge_onPresenceEvent onPresenceEvent;
        C_RtmEventHandlerBridge_onTopicEvent onTopicEvent;
        C_RtmEventHandlerBridge_onLockEvent onLockEvent;
        C_RtmEventHandlerBridge_onStorageEvent onStorageEvent;
        C_RtmEventHandlerBridge_onJoinResult onJoinResult;
        C_RtmEventHandlerBridge_onLeaveResult onLeaveResult;
        C_RtmEventHandlerBridge_onJoinTopicResult onJoinTopicResult;
        C_RtmEventHandlerBridge_onLeaveTopicResult onLeaveTopicResult;
        C_RtmEventHandlerBridge_onSubscribeTopicResult onSubscribeTopicResult;
        C_RtmEventHandlerBridge_onConnectionStateChanged onConnectionStateChanged;
        C_RtmEventHandlerBridge_onTokenPrivilegeWillExpire onTokenPrivilegeWillExpire;
        C_RtmEventHandlerBridge_onSubscribeResult onSubscribeResult;
        C_RtmEventHandlerBridge_onPublishResult onPublishResult;
        C_RtmEventHandlerBridge_onLoginResult onLoginResult;
        C_RtmEventHandlerBridge_onSetChannelMetadataResult onSetChannelMetadataResult;
        C_RtmEventHandlerBridge_onUpdateChannelMetadataResult onUpdateChannelMetadataResult;
        C_RtmEventHandlerBridge_onRemoveChannelMetadataResult onRemoveChannelMetadataResult;
        C_RtmEventHandlerBridge_onGetChannelMetadataResult onGetChannelMetadataResult;
        C_RtmEventHandlerBridge_onSetUserMetadataResult onSetUserMetadataResult;
        C_RtmEventHandlerBridge_onUpdateUserMetadataResult onUpdateUserMetadataResult;
        C_RtmEventHandlerBridge_onRemoveUserMetadataResult onRemoveUserMetadataResult;
        C_RtmEventHandlerBridge_onGetUserMetadataResult onGetUserMetadataResult;
        C_RtmEventHandlerBridge_onSubscribeUserMetadataResult onSubscribeUserMetadataResult;
        C_RtmEventHandlerBridge_onSetLockResult onSetLockResult;
        C_RtmEventHandlerBridge_onRemoveLockResult onRemoveLockResult;
        C_RtmEventHandlerBridge_onReleaseLockResult onReleaseLockResult;
        C_RtmEventHandlerBridge_onAcquireLockResult onAcquireLockResult;
        C_RtmEventHandlerBridge_onRevokeLockResult onRevokeLockResult;
        C_RtmEventHandlerBridge_onGetLocksResult onGetLocksResult;
        C_RtmEventHandlerBridge_onWhoNowResult onWhoNowResult;
        C_RtmEventHandlerBridge_onGetOnlineUsersResult onGetOnlineUsersResult;
        C_RtmEventHandlerBridge_onWhereNowResult onWhereNowResult;
        C_RtmEventHandlerBridge_onGetUserChannelsResult onGetUserChannelsResult;
        C_RtmEventHandlerBridge_onPresenceSetStateResult onPresenceSetStateResult;
        C_RtmEventHandlerBridge_onPresenceRemoveStateResult onPresenceRemoveStateResult;
        C_RtmEventHandlerBridge_onPresenceGetStateResult onPresenceGetStateResult;
    } C_RtmEventHandlerBridge_Callbacks;

    C_RtmEventHandlerBridge *C_RtmEventHandlerBridge_New(C_RtmEventHandlerBridge_Callbacks cbs, void *userData);
    void C_RtmEventHandlerBridge_Delete(C_RtmEventHandlerBridge *this_);
#pragma endregion C_RtmEventHandlerBridge

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_IRTM_EVENT_HANDLER_BRIDGE_H
