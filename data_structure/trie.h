//
// Created by JasonkayZK on 2022/3/26.
//

#ifndef MY_LEETCODE_TRIE_H
#define MY_LEETCODE_TRIE_H

#include "../utils/utils.h"

class TrieTree {
public:
    TrieTree() {
        this->children = std::vector<TrieTree *>(26, nullptr);
        this->isEnd = false;
    }

    void insert(const std::string &word);

    bool search(const std::string &word);

private:
    std::vector<TrieTree *> children;

    bool isEnd;
};

#endif //MY_LEETCODE_TRIE_H
