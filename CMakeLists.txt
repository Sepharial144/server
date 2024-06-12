
cmake_minimum_required (VERSION 3.20)

project("server" VERSION 0.0.1 DESCRIPTION "Server with client" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(package.cmake)
include(config.cmake)

message(STATUS "Package libraries: ${PACKAGE_LIBRARIES}")

file(GLOB_RECURSE SRC_FILES "source/*.hpp" "source/*.cpp")

add_executable(server ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_SOURCE_DIR}/source"
    "${PACKAGE_INCLUDE_DIR}"
)

#target_link_directories(${PROJECT_NAME} PUBLIC 
#)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PACKAGE_LIBRARIES}) 

