#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method 1: STL
class Solution {
private:

public:

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = int(nums.size());
        if (n <= 0) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do {
            res.emplace_back(nums);
        } while (next_permutation(begin(nums), end(nums)));
        return res;
    }

};
*/

/* Method 2: Backtrace */
class Solution {
 private:

  void dfs_helper(vector<int> &nums, vector<int> &cur_res, vector<vector<int>> &res,
                  vector<bool> &visited, int n) {

    if (cur_res.size() == n) {
      res.emplace_back(cur_res);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (visited[i]) continue;
      if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

      visited[i] = true;
      cur_res.emplace_back(nums[i]);
      dfs_helper(nums, cur_res, res, visited, n);
      cur_res.pop_back();
      visited[i] = false;
    }
  }

 public:

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 0) return {};

    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur_res;
    vector<bool> visited(n, false);

    dfs_helper(nums, cur_res, res, visited, n);

    return res;
  }

};

int main() {
  int a = 666;
  vector<int> b({1, 2, 3});
  string c = "hello world";

  // after
  debug(a, b, c);  // a=666, b=[ 1, 2, 3, ], c=hello world

  return 0;
}
