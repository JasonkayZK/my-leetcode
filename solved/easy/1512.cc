#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int numIdenticalPairs(vector<int> &nums) {
    unordered_map <int, int> m;
    for (int num: nums) {
      ++m[num];
    }

    int ans = 0;
    for (const auto &[k, v]: m) {
      ans += v * (v - 1) / 2;
    }
    return ans;
  }

 private:

};

int main() {

  return 0;
}
