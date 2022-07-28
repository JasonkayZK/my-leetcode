#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minSubArrayLen(int target, vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 0) return 0;

    int cur_sum = 0, res = INT_MAX;
    int l = 0, r = 0;
    while (r < n) {
      cur_sum += nums[r];

      while (cur_sum >= target) {
        res = min(res, r - l + 1);
        cur_sum -= nums[l];
        ++l;
      }
      ++r;
    }
    return res == INT_MAX ? 0 : res;
  }

 private:

};

int main() {

  return 0;
}
