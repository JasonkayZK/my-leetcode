#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool isUnivalTree(TreeNode *root) {
    if (root == nullptr) return true;
    if (root->left == nullptr && root->right == nullptr) return true;
    return dfs_helper(root, root->val);
  }

 private:

  bool dfs_helper(TreeNode *root, int val) {
    if (root == nullptr) return true;
    if (root->val != val) return false;
    return dfs_helper(root->left, val) && dfs_helper(root->right, val);
  }

};

int main() {

  return 0;
}
