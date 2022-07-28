#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int repeatedNTimes(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 0) return -1;
    if (n <= 2) return nums[0];

    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) return nums[i];
    }
    return nums[n - 1];
  }

 private:

};

int main() {

  return 0;
}
