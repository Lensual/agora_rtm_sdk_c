#ifndef C_I_AGORA_RTM_STORAGE_H
#define C_I_AGORA_RTM_STORAGE_H

#include "C_AgoraRtmBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtm

  /**
   * Metadata options.
   */
  struct C_MetadataOptions
  {
    /**
     * Indicates whether or not to notify server update the modify timestamp of metadata
     */
    bool recordTs;
    /**
     * Indicates whether or not to notify server update the modify user id of metadata
     */
    bool recordUserId;
  };
  struct C_MetadataOptions *C_MetadataOptions_New();
  void C_MetadataOptions_Delete(struct C_MetadataOptions *this_);

  struct C_MetadataItem
  {
    /**
     * The key of the metadata item.
     */
    const char *key;
    /**
     * The value of the metadata item.
     */
    const char *value;
    /**
     * The User ID of the user who makes the latest update to the metadata item.
     */
    const char *authorUserId;
    /**
     * The revision of the metadata item.
     */
    int64_t revision;
    /**
     * The Timestamp when the metadata item was last updated.
     */
    int64_t updateTs;
  };
  struct C_MetadataItem *C_MetadataItem_New();
  void C_MetadataItem_Delete(struct C_MetadataItem *this_);

  typedef void C_IMetadata;
#pragma region C_IMetadata
  /**
   * Set the major revision of metadata.
   *
   * @param [in] revision The major revision of the metadata.
   */
  void C_IMetadata_setMajorRevision(C_IMetadata *this_, const int64_t revision);
  /**
   * Get the major revision of metadata.
   *
   * @return the major revision of metadata.
   */
  int64_t C_IMetadata_getMajorRevision(C_IMetadata *this_);
  /**
   * Add or revise a metadataItem to current metadata.
   */
  void C_IMetadata_setMetadataItem(C_IMetadata *this_, const struct C_MetadataItem *item);
  /**
   * Get the metadataItem array of current metadata.
   *
   * @param [out] items The address of the metadataItem array.
   * @param [out] size The size the metadataItem array.
   */
  void C_IMetadata_getMetadataItems(C_IMetadata *this_, const struct C_MetadataItem **items, size_t *size);
  /**
   * Clear the metadataItem array & reset major revision
   */
  void C_IMetadata_clearMetadata(C_IMetadata *this_);
  /**
   * Release the metadata instance.
   */
  void C_IMetadata_release(C_IMetadata *this_);
#pragma endregion C_IMetadata

  typedef void C_IRtmStorage;
#pragma endregion C_IRtmStorage
  /** Creates the metadata object and returns the pointer.
   * @return Pointer of the metadata object.
   */
  C_IMetadata *C_IRtmStorage_createMetadata(C_IRtmStorage *this_);

  /**
   * Set the metadata of a specified channel.
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [in] lock lock for operate channel metadata.
   * @param [out] requestId The unique ID of this request.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_setChannelMetadata(C_IRtmStorage *this_,
                                       const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId);
  /**
   * Update the metadata of a specified channel.
   *
   * @param [in] channelName The channel Name of the specified channel.
   * @param [in] channelType Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [in] lock lock for operate channel metadata.
   * @param [out] requestId The unique ID of this request.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_updateChannelMetadata(C_IRtmStorage *this_,
                                          const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId);
  /**
   * Remove the metadata of a specified channel.
   *
   * @param [in] channelName The channel Name of the specified channel.
   * @param [in] channelType Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [in] lock lock for operate channel metadata.
   * @param [out] requestId The unique ID of this request.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_removeChannelMetadata(C_IRtmStorage *this_,
                                          const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId);
  /**
   * Get the metadata of a specified channel.
   *
   * @param [in] channelName The channel Name of the specified channel.
   * @param [in] channelType Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE.
   * @param requestId The unique ID of this request.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_getChannelMetadata(C_IRtmStorage *this_,
                                       const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, uint64_t *requestId);

  /**
   * Set the metadata of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [out] requestId The unique ID of this request.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_setUserMetadata(C_IRtmStorage *this_,
                                    const char *userId, const C_IMetadata *data, const struct C_MetadataOptions *options, uint64_t *requestId);
  /**
   * Update the metadata of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [out] requestId The unique ID of this request.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_updateUserMetadata(C_IRtmStorage *this_,
                                       const char *userId, const C_IMetadata *data, const struct C_MetadataOptions *options, uint64_t *requestId);
  /**
   * Remove the metadata of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [out] requestId The unique ID of this request.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_removeUserMetadata(C_IRtmStorage *this_,
                                       const char *userId, const C_IMetadata *data, const struct C_MetadataOptions *options, uint64_t *requestId);
  /**
   * Get the metadata of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [out] requestId The unique ID of this request.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_getUserMetadata(C_IRtmStorage *this_, const char *userId, uint64_t *requestId);

  /**
   * Subscribe the metadata update event of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_subscribeUserMetadata(C_IRtmStorage *this_, const char *userId, uint64_t *requestId);
  /**
   * unsubscribe the metadata update event of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtmStorage_unsubscribeUserMetadata(C_IRtmStorage *this_, const char *userId);
#pragma endregion C_IRtmStorage

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_RTM_STORAGE_H
