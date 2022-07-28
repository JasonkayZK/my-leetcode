#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return root;

    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;

    return root;
  }

};

int main() {

  return 0;
}
