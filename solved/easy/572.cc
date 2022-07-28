#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr) return true;
    if (root == nullptr || subRoot == nullptr) return false;

    queue < TreeNode * > q;
    q.emplace(root);
    while (!q.empty()) {
      int cnt = int(q.size());
      for (int i = 0; i < cnt; ++i) {
        auto *cur_node = q.front();
        q.pop();
        if (cur_node->val == subRoot->val && is_same(cur_node, subRoot)) return true;

        if (cur_node->left != nullptr) q.emplace(cur_node->left);
        if (cur_node->right != nullptr) q.emplace(cur_node->right);
      }
    }
    return false;
  }

 private:

  bool is_same(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    return root1->val == root2->val && is_same(root1->left, root2->left) && is_same(root1->right, root2->right);
  }

};

int main() {

  return 0;
}
