#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool canBeEqual(vector<int> &target, vector<int> &arr) {
    int m = int(target.size()), n = int(arr.size());
    if (m != n) return false;

    unordered_map<int, int> um;
    for (int i = 0; i < m; ++i) {
      ++um[target[i]];
      --um[arr[i]];
    }
    return std::all_of(um.begin(), um.end(),
                       [&](const auto &item) {
                         return item.second == 0;
                       });
  }

 private:

};

int main() {

  return 0;
}
