#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) return new TreeNode(val);

    if (root->val > val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }

};

int main() {

  return 0;
}
