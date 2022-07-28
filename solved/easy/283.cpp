#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  void moveZeroes(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 1) return;

    int l = 0, r = l;

    while (r < n) {
      if (nums[r] != 0) {
        swap(nums[l], nums[r]);
        l++;
      }
      r++;
    }
  }

};

int main() {

  vector<int> l = {1, 0};
  Solution().moveZeroes(l);

  return 0;
}
