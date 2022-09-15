#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxProductDifference(vector<int> &nums) {
    int n = int(nums.size());
    sort(nums.begin(), nums.end());
    int y = nums[0], z = nums[1], w = nums[n - 1], x = nums[n - 2];
    return w * x - y * z;
  }

 private:

};

int main() {

  return 0;
}
