#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr) return {};

    vector<vector<int>> ret;
    deque<TreeNode *> q;
    q.emplace_front(root);
    bool l2r = true;
    while (!q.empty()) {
      vector<int> level;
      int size = int(q.size());
      for (int i = 0; i < size; ++i) {
        if (l2r) {
          auto *node = q.front();
          q.pop_front();
          level.push_back(node->val);
          if (node->left != nullptr) q.push_back(node->left);
          if (node->right != nullptr) q.push_back(node->right);
        } else {
          auto *node = q.back();
          q.pop_back();
          level.push_back(node->val);
          if (node->right != nullptr) q.push_front(node->right);
          if (node->left != nullptr) q.push_front(node->left);
        }
      }
      ret.push_back(level);
      l2r = !l2r;
    }

    return ret;
  }

 private:

};

int main() {

  TreeNode *root = new TreeNode(3);
//  root->left = new TreeNode(9);
//  root->right = new TreeNode(20);
//  root->right->left = new TreeNode(15);
//  root->right->right = new TreeNode(7);

  std::cout << Solution().zigzagLevelOrder(root);

  return 0;
}
