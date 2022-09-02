#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int longestUnivaluePath(TreeNode *root) {
    if (root == nullptr) return 0;
    res = 0;
    dfs_helper(root, root->val);
    return res;
  }

 private:

  int dfs_helper(TreeNode *root, int val) {
    if (root == nullptr) return 0;
    int leftVal = dfs_helper(root->left, root->val);
    int rightVal = dfs_helper(root->right, root->val);

    res = max(res, leftVal + rightVal);
    if (root->val != val) {
      return 0;
    }

    return 1 + max(leftVal, rightVal);
  }

  int res;

};

int main() {

  return 0;
}
