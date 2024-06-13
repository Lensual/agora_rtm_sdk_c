// 引入AgoraRTM SDK
#include "IAgoraRtmStorage.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmStorage.h"

#pragma region agora

#pragma region agora::rtm

struct C_MetadataOptions *C_MetadataOptions_New()
{
  return (C_MetadataOptions *)new MetadataOptions();
}
void C_MetadataOptions_Delete(struct C_MetadataOptions *this_)
{
  delete (MetadataOptions *)this_;
}

struct C_MetadataItem *C_MetadataItem_New()
{
  return (C_MetadataItem *)new MetadataItem();
}
void C_MetadataItem_Delete(struct C_MetadataItem *this_)
{
  delete (MetadataItem *)this_;
}

#pragma region C_IMetadata
void C_IMetadata_setMajorRevision(C_IMetadata *this_, const int64_t revision)
{
  ((IMetadata *)this_)->setMajorRevision(revision);
}
int64_t C_IMetadata_getMajorRevision(C_IMetadata *this_)
{
  return ((IMetadata *)this_)->getMajorRevision();
}
void C_IMetadata_setMetadataItem(C_IMetadata *this_, const struct C_MetadataItem *item)
{
  ((IMetadata *)this_)->setMetadataItem(*(const MetadataItem *)item);
}
void C_IMetadata_getMetadataItems(C_IMetadata *this_, const struct C_MetadataItem **items, size_t *size)
{
  ((IMetadata *)this_)->getMetadataItems((const MetadataItem **)items, size);
}
void C_IMetadata_clearMetadata(C_IMetadata *this_)
{
  ((IMetadata *)this_)->clearMetadata();
}
void C_IMetadata_release(C_IMetadata *this_)
{
  ((IMetadata *)this_)->release();
}
#pragma endregion C_IMetadata

#pragma region C_IRtmStorage
C_IMetadata *C_IRtmStorage_createMetadata(C_IRtmStorage *this_)
{
  return ((IRtmStorage *)this_)->createMetadata();
}

int C_IRtmStorage_setChannelMetadata(C_IRtmStorage *this_,
                                     const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->setChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, (const IMetadata *)data, *(const struct MetadataOptions *)options, lockName, *requestId);
}
int C_IRtmStorage_updateChannelMetadata(C_IRtmStorage *this_,
                                        const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->updateChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, (const IMetadata *)data, *(const struct MetadataOptions *)options, lockName, *requestId);
}
int C_IRtmStorage_removeChannelMetadata(C_IRtmStorage *this_,
                                        const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_IMetadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->removeChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, (const IMetadata *)data, *(const struct MetadataOptions *)options, lockName, *requestId);
}
int C_IRtmStorage_getChannelMetadata(C_IRtmStorage *this_,
                                     const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->getChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *requestId);
}

int C_IRtmStorage_setUserMetadata(C_IRtmStorage *this_,
                                  const char *userId, const C_IMetadata *data, const struct C_MetadataOptions *options, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->setUserMetadata(userId, (const IMetadata *)data, *(const struct MetadataOptions *)options, *requestId);
}
int C_IRtmStorage_updateUserMetadata(C_IRtmStorage *this_,
                                     const char *userId, const C_IMetadata *data, const struct C_MetadataOptions *options, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->updateUserMetadata(userId, (const IMetadata *)data, *(const struct MetadataOptions *)options, *requestId);
}
int C_IRtmStorage_removeUserMetadata(C_IRtmStorage *this_,
                                     const char *userId, const C_IMetadata *data, const struct C_MetadataOptions *options, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->removeUserMetadata(userId, (const IMetadata *)data, *(const struct MetadataOptions *)options, *requestId);
}
int C_IRtmStorage_getUserMetadata(C_IRtmStorage *this_, const char *userId, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->getUserMetadata(userId, *requestId);
}

int C_IRtmStorage_subscribeUserMetadata(C_IRtmStorage *this_, const char *userId, uint64_t *requestId)
{
  return ((IRtmStorage *)this_)->subscribeUserMetadata(userId, *requestId);
}
int C_IRtmStorage_unsubscribeUserMetadata(C_IRtmStorage *this_, const char *userId)
{
  return ((IRtmStorage *)this_)->unsubscribeUserMetadata(userId);
}
#pragma endregion C_IRtmStorage

#pragma endregion agora::rtm

#pragma endregion agora
