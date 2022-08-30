#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(2 * n);
    for (int i = 0; i < n; i++) {
      ans[2 * i] = nums[i];
      ans[2 * i + 1] = nums[i + n];
    }
    return ans;
  }

 private:



};

int main() {



  return 0;
}
