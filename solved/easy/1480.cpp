#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<int> runningSum(vector<int> &nums) {
    int n = nums.size();
    if (n <= 0) return nums;

    vector<int> res(n, 0);
    res[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      res[i] = nums[i] + res[i - 1];
    }
    return res;
  }

};

int main() {

  vector<int> l = {1, 1, 1, 1, 1};
  Solution().runningSum(l);

  return 0;
}
