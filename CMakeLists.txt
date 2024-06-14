
cmake_minimum_required (VERSION 3.20)

project("server" VERSION 0.0.1 DESCRIPTION "Server with client" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(package.cmake)
include(config.cmake)

message(STATUS "Package libraries: ${PACKAGE_LIBRARIES}")

file(GLOB_RECURSE SRC_SERVER_FILES "source/*.hpp" "source/*.cpp")
list(FILTER SRC_SERVER_FILES EXCLUDE REGEX ".client")

#file(GLOB_RECURSE SRC_CLIENT_FILES "source/client/*.cpp")
#list(FILTER SRC_CLIENT_FILES EXCLUDE REGEX ".server")

add_executable(server ${SRC_SERVER_FILES})
#add_executable(client ${SRC_CLIENT_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_SOURCE_DIR}/source"
    "${PACKAGE_INCLUDE_DIR}"
)

#target_link_directories(${PROJECT_NAME} PUBLIC 
#)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PACKAGE_LIBRARIES}) 

