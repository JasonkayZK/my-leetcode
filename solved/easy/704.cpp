#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int search(vector<int> &nums, int target) {
    int n = int(nums.size());
    if (n <= 0) return -1;

    int l = 0, r = n - 1;
    while (l < r) {
      int mid = ((r - l) >> 1) + l;

      if (nums[mid] == target) return mid;
      else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    if (l < n && nums[l] == target) return l;
    else if (r >= 0 && nums[r] == target) return r;
    else return -1;
  }

};

int main() {

  vector<int> l = {2, 5};
  Solution().search(l, 0);

  return 0;
}
