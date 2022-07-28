#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int massage(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    int res = max(dp[0], dp[1]);
    for (int i = 2; i < n; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      res = max(res, dp[i]);
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
