#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int findDuplicate(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 2) return nums[0];

    int slow = 0, fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }

};

int main() {

  vector<int> l = {4, 3, 1, 4, 2};
  Solution().findDuplicate(l);

  return 0;
}
