#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 private:

 public:

  vector<int> intersection(vector<vector<int>> &nums) {
    if (nums.empty() || nums[0].empty()) return {};

    int m = int(nums.size()), n = int(nums[0].size());
    vector<int> v(1005, 0);
    for (const auto &item : nums) {
      for (const auto &x : item) {
        v[x]++;
      }
    }

    vector<int> res;
    for (int i = 0; i < 1005; ++i) {
      if (v[i] == m) res.push_back(i);
    }
    return res;
  }

};

int main() {
  int a = 666;
  vector<int> b({1, 2, 3});
  string c = "hello world";

  // after
  debug(a, b, c);  // a=666, b=[ 1, 2, 3, ], c=hello world

  return 0;
}
