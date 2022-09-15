#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> smallerNumbersThanCurrent(vector<int> &&nums) {
    vector<int> map(100 + 1);
    for (const auto &item : nums) {
      ++map[item];
    }

    int prev = 0, cur = 0;
    for (int i = 1; i <= 100; ++i) {
      map[i] += map[i - 1];
    }

    int n = int(nums.size());
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
      ret[i] = nums[i] == 0 ? 0 : map[nums[i] - 1];
    }
    return ret;
  }

 private:

};

int main() {

  Solution().smallerNumbersThanCurrent({5, 0, 10, 0, 10, 6});

  return 0;
}
