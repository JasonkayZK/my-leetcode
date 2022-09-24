#include "../../utils/utils.h"
#include "../../data_structure/list.h"
#include "../../data_structure/tree.h"
#include "../../data_structure/trie.h"
#include "../../data_structure/segment_tree.h"
#include "../../data_structure/union_find.h"

class Solution {
 public:

  int transportationHub(vector<vector<int>> &&path) {
    unordered_map<int, unordered_set<int>> from_to;
    unordered_map<int, unordered_set<int>> to_from;
    unordered_set<int> s;
    for (const auto &item : path) {
      s.emplace(item[0]);
      s.emplace(item[1]);
      from_to[item[0]].emplace(item[1]);
      to_from[item[1]].emplace(item[0]);
    }

    auto n = s.size();
    for (const auto &[k, v] : to_from) {
      if (v.size() == n - 1) {
        if (from_to.count(k) <= 0) return k;
      }
    }
    return -1;
  }

 private:

};

int main() {

  Solution().transportationHub({{0, 1}, {0, 3}, {1, 3}, {2, 0}, {2, 3}});

  return 0;
}
