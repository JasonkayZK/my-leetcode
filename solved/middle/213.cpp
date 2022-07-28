#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  int rob(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    return max(rob_helper(nums, 0, n - 1), rob_helper(nums, 1, n));
  }

};

int main() {

  vector<int> l = {1};
  std::cout << Solution().rob(l);

  return 0;
}
