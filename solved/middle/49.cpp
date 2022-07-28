#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  string hash(const string &str) {
    char cnt[26];
    fill(cnt, cnt + 26, 0);
    for (const auto &item : str) {
      cnt[item - 'a']++;
    }

    string res;
    for (const auto &item : cnt) {
      res.push_back(item + 'a');
    }
    return res;
  }

 public:

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m{};

    for (const auto &item : strs) {
      // generate hash
      auto hashed = hash(item);
      m[hashed].push_back(item);
    }

    // yield result
    vector<vector<string>> res;
    for (const auto &item : m) {
      res.push_back(item.second);
    }
    return res;
  }

};

int main() {

  vector<string> l{"bdddddddddd", "bbbbbbbbbbc"};
  Solution().groupAnagrams(l);

  return 0;
}
