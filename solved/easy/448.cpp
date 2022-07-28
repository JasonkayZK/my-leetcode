#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = int(nums.size());

    // format array
    for (auto &num : nums) {
      int x = (num - 1) % n;
      nums[x] += n;
    }

    // find not corresponding
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (nums[i] <= n) {
        res.push_back(i + 1);
      }
    }
    return res;
  }

};

int main() {

  vector<int> l = {4, 3, 2, 7, 8, 2, 3, 1};
  Solution().findDisappearedNumbers(l);

  return 0;
}
