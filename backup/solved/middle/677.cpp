#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <queue>
#include <set>
#include <random>

using namespace std;

class TrieNode {
 public:
  int val;
  TrieNode *next[26]{};

  TrieNode() {
    this->val = 0;
    for (auto &i : this->next) {
      i = nullptr;
    }
  }

};

class MapSum {
 private:
  TrieNode *root;
  unordered_map<string, int> cnt;

 public:
  MapSum() {
    this->root = new TrieNode();
  }

  void insert(string key, int val) {
    int delta = val;

    // 先减去原值（变化的量）
    if (cnt.count(key)) {
      delta -= cnt[key];
    }

    // trieTree所有前缀加上该值；
    cnt[key] = val;
    TrieNode *node = root;
    for (auto c : key) {
      if (node->next[c - 'a'] == nullptr) {
        node->next[c - 'a'] = new TrieNode();
      }
      node = node->next[c - 'a'];
      node->val += delta;
    }
  }

  int sum(string prefix) {
    TrieNode *node = root;
    for (auto c : prefix) {
      if (node->next[c - 'a'] == nullptr) {
        return 0;
      } else {
        node = node->next[c - 'a'];
      }
    }
    return node->val;
  }
};
