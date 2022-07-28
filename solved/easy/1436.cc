#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string destCity(vector<vector<string>> &paths) {
    unordered_map<string, int> m;
    for (const auto &item : paths) {
      ++m[item[0]];
      if (m.count(item[1]) <= 0) m.emplace(make_pair(item[1], 0));
    }

    for (const auto &[k, v] : m) {
      if (v == 0) return k;
    }
    return "";
  }

 private:

};

int main() {

  return 0;
}
