set(CMAKE_SKIP_RPATH TRUE)
set(CMAKE_SKIP_BUILD_RPATH TRUE)
set(CMAKE_SKIP_INSTALL_RPATH TRUE)

cmake_minimum_required(VERSION 3.0.0)
project(agora_rtm_sdk_c VERSION 2.1.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(AgoraRtmSdk)

# this project
add_library(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC "./include")
aux_source_directory(./src SRCS)
aux_source_directory(./src/bridge BRIDGE_SRCS)
target_sources(${PROJECT_NAME} PRIVATE ${SRCS} ${BRIDGE_SRCS})

# include AgoraRTM SDK
target_include_directories(${PROJECT_NAME} PRIVATE agora_rtm_sdk)
target_link_libraries(${PROJECT_NAME} agora_rtm_sdk)
