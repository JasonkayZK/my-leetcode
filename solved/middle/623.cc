#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (root == nullptr) return new TreeNode{val};
    if (depth <= 0) return root;
    if (depth == 1) return new TreeNode{val, root, nullptr};

    vector<TreeNode *> curLevel(1, root);
    for (int i = 1; i < depth - 1; i++) {
      vector<TreeNode *> tmpt;
      for (auto &node : curLevel) {
        if (node->left != nullptr) {
          tmpt.emplace_back(node->left);
        }
        if (node->right != nullptr) {
          tmpt.emplace_back(node->right);
        }
      }
      curLevel = std::move(tmpt);
    }
    for (auto &node : curLevel) {
      node->left = new TreeNode(val, node->left, nullptr);
      node->right = new TreeNode(val, nullptr, node->right);
    }
    return root;
  }

 private:

};

int main() {

  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);

  (new Solution())->addOneRow(root, 1, 3);

  return 0;
}
