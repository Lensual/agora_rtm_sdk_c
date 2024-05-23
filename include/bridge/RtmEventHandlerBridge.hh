#pragma once

#include "IAgoraRtmClient.h"
using namespace agora::rtm;

#include "C_RtmEventHandlerBridge.h"

class RtmEventHandlerBridge : public IRtmEventHandler
{
public:
    RtmEventHandlerBridge(C_RtmEventHandlerBridge_Callbacks cbs, void *userData)
        : cbs_(cbs),
          userData_(userData) {}

    ~RtmEventHandlerBridge(){};

    /**
     * Occurs when receive a message.
     *
     * @param event details of message event.
     */
    void onMessageEvent(const MessageEvent &event) override;

    /**
     * Occurs when remote user presence changed
     *
     * @param event details of presence event.
     */
    void onPresenceEvent(const PresenceEvent &event) override;

    /**
     * Occurs when remote user join/leave topic or when user first join this channel,
     * got snapshot of topics in this channel
     *
     * @param event details of topic event.
     */
    void onTopicEvent(const TopicEvent &event) override;

    /**
     * Occurs when lock state changed
     *
     * @param event details of lock event.
     */
    void onLockEvent(const LockEvent &event) override;

    /**
     * Occurs when receive storage event
     *
     * @param event details of storage event.
     */
    void onStorageEvent(const StorageEvent &event) override;

    /**
     * Occurs when user join a stream channel.
     *
     * @param channelName The name of the channel.
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    void onJoinResult(const uint64_t requestId, const char *channelName, const char *userId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user leave a stream channel.
     *
     * @param channelName The name of the channel.
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    void onLeaveResult(const uint64_t requestId, const char *channelName, const char *userId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user join topic.
     *
     * @param channelName The name of the channel.
     * @param userId The id of the user.
     * @param topic The name of the topic.
     * @param meta The meta of the topic.
     * @param errorCode The error code.
     */
    void onJoinTopicResult(const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user leave topic.
     *
     * @param channelName The name of the channel.
     * @param userId The id of the user.
     * @param topic The name of the topic.
     * @param meta The meta of the topic.
     * @param errorCode The error code.
     */
    void onLeaveTopicResult(const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, RTM_ERROR_CODE errorCode) override;

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
    void onSubscribeTopicResult(const uint64_t requestId, const char *channelName, const char *userId, const char *topic, UserList succeedUsers, UserList failedUsers, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when the connection state changes between rtm sdk and agora service.
     *
     * @param channelName The name of the channel.
     * @param state The new connection state.
     * @param reason The reason for the connection state change.
     */
    void onConnectionStateChanged(const char *channelName, RTM_CONNECTION_STATE state, RTM_CONNECTION_CHANGE_REASON reason) override;

    /**
     * Occurs when token will expire in 30 seconds.
     *
     * @param channelName The name of the channel.
     */
    void onTokenPrivilegeWillExpire(const char *channelName) override;

    /**
     * Occurs when subscribe a channel
     *
     * @param channelName The name of the channel.
     * @param errorCode The error code.
     */
    void onSubscribeResult(const uint64_t requestId, const char *channelName, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user publish message.
     *
     * @param requestId The related request id when user publish message
     * @param errorCode The error code.
     */
    void onPublishResult(const uint64_t requestId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user login.
     *
     * @param errorCode The error code.
     */
    void onLoginResult(RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user setting the channel metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param errorCode The error code.
     */
    void onSetChannelMetadataResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user updating the channel metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param errorCode The error code.
     */
    void onUpdateChannelMetadataResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user removing the channel metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param errorCode The error code.
     */
    void onRemoveChannelMetadataResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user try to get the channel metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param data The result metadata of getting operation.
     * @param errorCode The error code.
     */
    void onGetChannelMetadataResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const IMetadata &data, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user setting the user metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    void onSetUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user updating the user metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    void onUpdateUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user removing the user metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    void onRemoveUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user try to get the user metadata
     *
     * @param requestId The related request id when user perform this operation
     * @param userId The id of the user.
     * @param data The result metadata of getting operation.
     * @param errorCode The error code.
     */
    void onGetUserMetadataResult(const uint64_t requestId, const char *userId, const IMetadata &data, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user subscribe a user metadata
     *
     * @param userId The id of the user.
     * @param errorCode The error code.
     */
    void onSubscribeUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user set a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    void onSetLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user delete a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    void onRemoveLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user release a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    void onReleaseLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user acquire a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    void onAcquireLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode, const char *errorDetails) override;

    /**
     * Occurs when user revoke a lock
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockName The name of the lock.
     * @param errorCode The error code.
     */
    void onRevokeLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when user try to get locks from the channel
     *
     * @param channelName The name of the channel.
     * @param channelType The type of the channel.
     * @param lockDetailList The details of the locks.
     * @param count The count of the locks.
     * @param errorCode The error code.
     */
    void onGetLocksResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const LockDetail *lockDetailList, const size_t count, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when query who joined this channel
     *
     * @param requestId The related request id when user perform this operation
     * @param userStatesList The states the users.
     * @param count The user count.
     * @param errorCode The error code.
     */
    void onWhoNowResult(const uint64_t requestId, const UserState *userStateList, const size_t count, const char *nextPage, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when query who joined this channel
     *
     * @param requestId The related request id when user perform this operation
     * @param userStatesList The states the users.
     * @param count The user count.
     * @param errorCode The error code.
     */
    void onGetOnlineUsersResult(const uint64_t requestId, const UserState *userStateList, const size_t count, const char *nextPage, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when query which channels the user joined
     *
     * @param requestId The related request id when user perform this operation
     * @param channels The channel informations.
     * @param count The channel count.
     * @param errorCode The error code.
     */
    void onWhereNowResult(const uint64_t requestId, const ChannelInfo *channels, const size_t count, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when query which channels the user joined
     *
     * @param requestId The related request id when user perform this operation
     * @param channels The channel informations.
     * @param count The channel count.
     * @param errorCode The error code.
     */
    void onGetUserChannelsResult(const uint64_t requestId, const ChannelInfo *channels, const size_t count, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when set user presence
     *
     * @param requestId The related request id when user perform this operation
     * @param errorCode The error code.
     */
    void onPresenceSetStateResult(const uint64_t requestId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when delete user presence
     *
     * @param requestId The related request id when user perform this operation
     * @param errorCode The error code.
     */
    void onPresenceRemoveStateResult(const uint64_t requestId, RTM_ERROR_CODE errorCode) override;

    /**
     * Occurs when get user presence
     *
     * @param requestId The related request id when user perform this operation
     * @param states The user states
     * @param errorCode The error code.
     */
    void onPresenceGetStateResult(const uint64_t requestId, const UserState &state, RTM_ERROR_CODE errorCode) override;

private:
    C_RtmEventHandlerBridge_Callbacks cbs_;
    void *userData_;
};
