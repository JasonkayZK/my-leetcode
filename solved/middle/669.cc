#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (root == nullptr) return nullptr;
    if (root->val < low) return trimBST(root->right, low, high);
    else if (root->val > high) return trimBST(root->left, low, high);
    else {
      root->left = trimBST(root->left, low, high);
      root->right = trimBST(root->right, low, high);
      return root;
    }
  }

 private:

};

int main() {

  return 0;
}
