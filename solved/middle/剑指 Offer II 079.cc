#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs_helper(nums, res, cur, 0);
    return res;
  }

 private:

  void dfs_helper(const vector<int> &nums,
                  vector<vector<int>> &res,
                  vector<int> &cur, int idx) {

    if (idx >= nums.size()) {
      res.push_back(cur);
      return;
    }

    cur.push_back(nums[idx]);
    dfs_helper(nums, res, cur, idx + 1);
    cur.pop_back();
    dfs_helper(nums, res, cur, idx + 1);
  }

};

int main() {

  return 0;
}
