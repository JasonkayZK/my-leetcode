#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxAscendingSum(vector<int> &&nums) {
    int res = nums[0], cur_sum = 0, prev_val = nums[0];
    for (const auto &item : nums) {
      if (item > prev_val) {
        cur_sum += item;
      } else {
        cur_sum = item;
      }
      res = max(res, cur_sum);
      prev_val = item;
    }
    return res;
  }

 private:

};

int main() {

  Solution().maxAscendingSum({3, 6, 10, 1, 8, 9, 9, 8, 9});

  return 0;
}
