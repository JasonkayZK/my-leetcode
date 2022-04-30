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

if (MACOS)
    set(BOOST_ROOT "/usr/local/include/boost")
    include_directories(/usr/local/include) # header files searching path
    link_directories(/usr/local/lib) # library files searching path
elseif (WINDOWS)
    set(BOOST_ROOT " E:\\libs\\boost_1_78_0")
    include_directories(${BOOST_ROOT}) # header files searching path
    link_directories(${BOOST_ROOT}\\stage\\lib) # library files searching path
endif ()

add_executable(solution_tpl solution_tpl.cpp utils/utils.cpp utils/utils.h data_structure/tree.cpp data_structure/tree.h data_structure/list.cpp data_structure/list.h data_structure/trie.cpp data_structure/trie.h data_structure/segment_tree.cpp data_structure/segment_tree.h data_structure/union_find.h)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(solution_tpl PRIVATE fmt::fmt)
