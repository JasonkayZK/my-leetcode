#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int longestNiceSubarray(vector<int> &nums) {
    int size = int(nums.size());
    if (size <= 1) return size;

    int res = 1, l = 0, r = 1;
    while (r < size) {
      if (l == r) {
        ++r;
        continue;
      }

      int cur_res = true, i;
      for (i = l; i < r; ++i) {
        if ((nums[i] & nums[r]) != 0) {
          cur_res = false;
          break;
        }
      }

      if (cur_res) {
        ++r;
        res = max(r - l, res);
      } else {
        if (l == i) {
          ++l;
        } else {
          l = i;
        }
      }
    }

    return res <= 0 ? 1 : res;
  }

 private:

};

int main() {

  return 0;
}
