#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string customSortString(string order, string s) {
    unordered_map<char, int> c_map;
    for (int i = 0; i < order.size(); ++i) {
      c_map[order[i]] = i;
    }

    auto cmp = [&c_map](char const a, char const b) {
      return c_map[a] < c_map[b];
    };

    sort(s.begin(), s.end(), cmp);
    return s;
  }

 private:

};

int main() {

  return 0;
}
