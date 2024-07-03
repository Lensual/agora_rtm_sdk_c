# AgoraRTM SDK
include(ExternalProject)
ExternalProject_Add(agora_rtm_sdk_download
  URL               https://download.agora.io/rtm2/release/Agora_RTM_C%2B%2B_SDK_for_Linux_v2.1.12.zip
  URL_HASH          MD5=c679085d195bf5c9edaff82446f07bcf
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  UPDATE_COMMAND    ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
  )
ExternalProject_Get_Property(agora_rtm_sdk_download SOURCE_DIR)
set(AGORA_RTM_SDK_LIB_DIR ${SOURCE_DIR}/rtm/sdk)
set(AGORA_RTM_SDK_INCLUDE_DIR ${SOURCE_DIR}/rtm/sdk/high_level_api/include)
unset(SOURCE_DIR)

add_library(agora_rtm_sdk SHARED IMPORTED)
add_dependencies(agora_rtm_sdk agora_rtm_sdk_download)
file(MAKE_DIRECTORY ${AGORA_RTM_SDK_INCLUDE_DIR})
set_property(TARGET agora_rtm_sdk PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${AGORA_RTM_SDK_INCLUDE_DIR})
set_property(TARGET agora_rtm_sdk PROPERTY IMPORTED_LOCATION ${AGORA_RTM_SDK_LIB_DIR}/libagora_rtm_sdk.so)
