#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  double findMaxAverage(vector<int> &nums, int k) {
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    int maxSum = sum;
    for (int i = k; i < n; i++) {
      sum = sum - nums[i - k] + nums[i];
      maxSum = max(maxSum, sum);
    }
    return 1.0 * maxSum / k;
  }

 private:

};

int main() {

  return 0;
}
