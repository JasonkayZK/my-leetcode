cmake_minimum_required(VERSION 3.16)
project(my_leetcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(solution_tpl solution_tpl.cpp utils/utils.cpp utils/utils.h data_structure/tree.cpp data_structure/tree.h data_structure/list.cpp data_structure/list.h data_structure/trie.cpp data_structure/trie.h)
