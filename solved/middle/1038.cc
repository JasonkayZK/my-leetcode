#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  TreeNode *bstToGst(TreeNode *root) {
    cur = 0;
    dfs_helper(root);
    return root;
  }

 private:

  void dfs_helper(TreeNode *root) {
    if (root == nullptr) return;

    if (root->right != nullptr) {
      dfs_helper(root->right);
    }
    root->val += cur;
    cur = root->val;

    if (root->left != nullptr) {
      dfs_helper(root->left);
    }
  }

  int cur;

};

int main() {

  return 0;
}
