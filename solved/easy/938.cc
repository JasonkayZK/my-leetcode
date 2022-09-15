#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int rangeSumBST(TreeNode *root, int low, int high) {
    res = 0;
    dfs_helper(root, low, high);
    return res;
  }

 private:

  void dfs_helper(TreeNode *root, const int low, const int high) {
    if (root == nullptr) return;

    if (root->val < low) return dfs_helper(root->right, low, high);
    else if (root->val > high) return dfs_helper(root->left, low, high);
    else {
      res += root->val;
      dfs_helper(root->left, low, high);
      dfs_helper(root->right, low, high);
    }
  }

  int res;

};

int main() {

  return 0;
}
