#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minStartValue(vector<int> &nums) {
    if (nums.empty()) { return 1; }

    int cur_sum = nums[0], min_sum = nums[0];
    for (int i = 1, len = int(nums.size()); i < len; ++i) {
      cur_sum += nums[i];
      min_sum = std::min(cur_sum, min_sum);
    }

    return min_sum >= 1 ? 1 : 1 - min_sum;
  }

 private:

};

int main() {

  return 0;
}
