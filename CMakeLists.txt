cmake_minimum_required(VERSION 3.10)
project(syscall)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_package(CURL REQUIRED)

file(GLOB SOURCES "lib/*.cpp" "main.cpp")

add_executable(syscall ${SOURCES})

target_include_directories(syscall PRIVATE include)
target_link_libraries(syscall PRIVATE ${CURL_LIBRARIES})

target_compile_options(syscall PRIVATE -Iinclude)