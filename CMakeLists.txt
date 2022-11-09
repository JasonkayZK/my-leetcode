cmake_minimum_required(VERSION 3.16)
project(my_leetcode)

# os check
if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif (CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()

set(CMAKE_CXX_STANDARD 20)

add_executable(solution_tpl solution_tpl.cc)
