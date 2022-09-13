#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int specialArray(vector<int> &nums) {
    sort(nums.rbegin(), nums.rend());
    int l = 1, len = nums.size(), r = len;

    while (l <= r) {
      int mid = ((r - l) >> 1) + l;
      if (nums[mid - 1] >= mid) {
        if (mid == len || nums[mid] < mid) {
          return mid;
        } else {
          l = mid + 1;
        }
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }

 private:

};

int main() {

  return 0;
}
