#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int arithmeticTriplets(vector<int> &nums, int diff) {
    int n = int(nums.size()), res = 0;

    int l = 0, m = 1, r = 2;

    while (r < n) {
      while (m < r && nums[m] + diff < nums[r]) ++m;
      if (nums[m] + diff == nums[r]) {
        while (l < m && nums[l] + diff < nums[m]) ++l;
        if (nums[l] + diff == nums[m]) ++res;
      }
      ++r;
    }

    return res;
  }

 private:

};

int main() {

  return 0;
}
