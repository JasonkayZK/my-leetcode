#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (root->val < val) {
      return new TreeNode(val, root, nullptr);
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
  }

 private:

};

int main() {

  return 0;
}
