#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxSubArray(vector<int> &nums) {
    int pre = 0, maxAns = nums[0];
    for (const auto &x: nums) {
      pre = max(pre + x, x);
      maxAns = max(maxAns, pre);
    }
    return maxAns;
  }

 private:

};

int main() {

  return 0;
}
