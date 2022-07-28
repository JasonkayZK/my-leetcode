//
// Created by JasonkayZK on 2022/3/26.
//

#include "trie.h"

void TrieTree::insert(const std::string &word) {
  TrieTree *node = this;
  for (const auto &item : word) {
    int idx = item - 'a';
    if (node->children[idx] == nullptr) {
      node->children[idx] = new TrieTree();
    }

    node = node->children[idx];
  }

  node->isEnd = true;
}

bool TrieTree::search(const std::string &word) {
  TrieTree *node = this;
  for (const auto &item : word) {
    int idx = item - 'a';
    if (node->children[idx] == nullptr) {
      return false;
    }
    node = node->children[idx];
  }
  return node->isEnd;
}
