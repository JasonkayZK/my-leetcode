#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int waysToSplitArray(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 1) return 0;

    long long pre_sum[n];
    pre_sum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      pre_sum[i] = pre_sum[i - 1] + nums[i];
    }

    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (pre_sum[i] >= pre_sum[n - 1] - pre_sum[i]) ++res;
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
