#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minPairSum(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n / 2; ++i) {
      res = max(res, nums[i] + nums[n - 1 - i]);
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
