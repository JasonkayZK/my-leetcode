#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minMaxGame(vector<int> &nums) {
    int n = int(nums.size());
    while (n != 1) {
      int cnt = 0;
      for (int i = 0; i < n; i += 2, ++cnt) {
        if ((cnt & 1) == 0) {
          nums[cnt] = min(nums[i], nums[i + 1]);
        } else {
          nums[cnt] = max(nums[i], nums[i + 1]);
        }
      }
      n = cnt;
    }
    return nums[0];
  }

 private:

};

int main() {

  return 0;
}
