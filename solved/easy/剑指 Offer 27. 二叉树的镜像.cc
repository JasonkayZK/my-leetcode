#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  TreeNode *mirrorTree(TreeNode *root) {
    if (root == nullptr) return nullptr;
    auto *left = mirrorTree(root->left);
    auto *right = mirrorTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }

 private:

};

int main() {

  return 0;
}
