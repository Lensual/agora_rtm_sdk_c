cmake_minimum_required(VERSION 3.0.0)
project(agora_rtm_sdk_c VERSION 0.1.0)

# include AgoraRTM SDK
include(ExternalProject)
ExternalProject_Add(agora_rtm_sdk
  URL               https://download.agora.io/rtm2/release/Agora_RTM_C%2B%2B_SDK_for_Linux_v2.1.12.zip
  URL_HASH          MD5=c679085d195bf5c9edaff82446f07bcf
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  UPDATE_COMMAND    ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
set(AGORA_RTM_SDK_LIB_DIR ${CMAKE_BINARY_DIR}/agora_rtm_sdk-prefix/src/agora_rtm_sdk/rtm/sdk)
set(AGORA_RTM_SDK_INCLUDE_DIR ${CMAKE_BINARY_DIR}/agora_rtm_sdk-prefix/src/agora_rtm_sdk/rtm/sdk/high_level_api/include)
#set(AGORA_RTM_SDK_LIB_DIR ${CMAKE_BINARY_DIR}/../agora_rtm_sdk/Agora_RTM_SDK_for_Linux_MINI_RTM/rtm/sdk)
#set(AGORA_RTM_SDK_INCLUDE_DIR ${CMAKE_BINARY_DIR}/../agora_rtm_sdk/Agora_RTM_SDK_for_Linux_MINI_RTM/rtm/sdk/high_level_api/include)
include_directories(${AGORA_RTM_SDK_INCLUDE_DIR})
link_directories(${AGORA_RTM_SDK_LIB_DIR})

# this project
include_directories(./include)
aux_source_directory(./src DIR_SRCS)
aux_source_directory(./src/bridge DIR_BRIDGE)
add_library(${PROJECT_NAME} ${DIR_SRCS} ${DIR_BRIDGE})
