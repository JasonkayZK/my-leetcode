#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  void dfs_helper(const TreeNode *root, vector<vector<int>> &res, vector<int> &cur,
                  const int target, int cur_sum) {

    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) { // leaf node
      if (cur_sum + root->val == target) {
        // yield result
        cur.push_back(root->val);
        res.push_back(cur);

        // backtrace
        cur.pop_back();
        return;
      } else {
        return;
      }
    }

    // not leaf node
    cur_sum += root->val;
    cur.push_back(root->val);

    dfs_helper(root->left, res, cur, target, cur_sum);
    dfs_helper(root->right, res, cur, target, cur_sum);

    // backtrace
    cur_sum -= root->val;
    cur.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) return {};

    vector<vector<int>> res;
    vector<int> cur;
    dfs_helper(root, res, cur, targetSum, 0);
    return res;
  }

 private:

};

int main() {

  return 0;
}
