cmake_minimum_required(VERSION 3.19)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

project (hello-napi VERSION 0.1.0)

add_definitions(-DNAPI_VERSION=8)

set(CMAKE_BUILD_TYPE Release)
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR}/..)

include_directories(${CMAKE_JS_INC})

add_library(${PROJECT_NAME} SHARED
  ${CMAKE_JS_SRC}
  ${CMAKE_SOURCE_DIR}/src/bridge.cc)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api
  ${PROJECT_ROOT_DIR}/build/include)

target_link_libraries(${PROJECT_NAME} PRIVATE
  ${CMAKE_JS_LIB}
  ${PROJECT_ROOT_DIR}/build/lib/libhello.a)

if(MINGW AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
  # Generate node.lib
  execute_process(COMMAND dlltool -d ${CMAKE_JS_NODELIB_DEF} -l ${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif()
