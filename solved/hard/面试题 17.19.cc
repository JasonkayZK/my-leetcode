#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  /*
  vector<int> missingTwo(vector<int> &nums) {
    for (int i = 0; i < 3; ++i) nums.push_back(-1);
    int n = int(nums.size());
    for (int i = 0; i < n; ++i) {
      while (i != nums[i] && nums[i] != -1) swap(nums[i], nums[nums[i]]);
    }
    vector<int> res;
    for (int i = 1; i < n; ++i) {
      if (nums[i] == -1) res.push_back(i);
    }
    return res;
  }
*/

  vector<int> missingTwo(vector<int> &nums) {
    for (int i = 0; i < 3; ++i) nums.push_back(-1);
    int n = int(nums.size());
    for (int i = 0; i < n; ++i) {
      while (i != nums[i] && nums[i] != -1) swap(nums[i], nums[nums[i]]);
    }
    vector<int> res;
    for (int i = 1; i < n; ++i) {
      if (nums[i] == -1) res.push_back(i);
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
