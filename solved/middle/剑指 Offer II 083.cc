#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    dfs_helper(res, nums, 0, int(nums.size()));
    return res;
  }

 private:

  void dfs_helper(vector<vector<int>> &res,
                  vector<int> &cur,
                  int idx, const int n) {

    if (idx >= n) {
      res.push_back(cur);
      return;
    }

    for (int i = idx; i < n; ++i) {
      swap(cur[i], cur[idx]);
      dfs_helper(res, cur, idx + 1, n);
      swap(cur[i], cur[idx]);
    }
  }

};

int main() {

  return 0;
}
