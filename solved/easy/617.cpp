#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) return nullptr;

    if (root2 == nullptr) return root1;
    if (root1 == nullptr) return root2;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
  }

};

int main() {

  return 0;
}
