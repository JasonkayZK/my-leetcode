#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool evaluateTree(TreeNode* root) {
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr) return root->val == 1;

    if (root->val == 2) {
      return evaluateTree(root->left) || evaluateTree(root->right);
    } else {
      return evaluateTree(root->left) && evaluateTree(root->right);
    }
  }

 private:

};

int main() {

  return 0;
}
