#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int sumEvenGrandparent(TreeNode *root) {
    res = 0;
    if (root->left != nullptr) {
      dfs_helper(root, root->left, root->left->left);
      dfs_helper(root, root->left, root->left->right);
    }
    if (root->right != nullptr) {
      dfs_helper(root, root->right, root->right->left);
      dfs_helper(root, root->right, root->right->right);
    }

    return res;
  }

 private:

  void dfs_helper(TreeNode *grandparent, TreeNode *parent, TreeNode *cur) {
    if (cur == nullptr) return;

    if ((grandparent->val & 1) == 0) res += cur->val;
    dfs_helper(parent, cur, cur->left);
    dfs_helper(parent, cur, cur->right);
  }

  int res;

};

int main() {

  return 0;
}
