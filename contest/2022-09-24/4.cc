#include "../../utils/utils.h"
#include "../../data_structure/list.h"
#include "../../data_structure/tree.h"
#include "../../data_structure/trie.h"
#include "../../data_structure/segment_tree.h"
#include "../../data_structure/union_find.h"

/*
[1,1,0,null,null,null,1] 2
[1,1,1,1,null,null,1] 1
[0,null,0] 0
[1,0,0,1,0,1] 3
[1,null,1,0,0,1,null,null,null,0] 2

 */
class Solution {
 public:

  int closeLampInTree(TreeNode *root) {
    if (root == nullptr) return 0;
    auto res = dfs_helper(root);
    return min(res.first, res.second + 1);
  }

 private:

  pair<int, int> dfs_helper(TreeNode *cur) {
    if (cur == nullptr) return make_pair(INT_MAX, INT_MAX);

    pair<int, int> left{INT_MAX, INT_MAX}, right{INT_MAX, INT_MAX};
    if (cur->left != nullptr) left = dfs_helper(cur->left);
    if (cur->right != nullptr) right = dfs_helper(cur->right);

    int to_zero = INT_MAX, to_one = INT_MAX;
    if (cur->val == 0) { // to zero
      if ((left.first == INT_MAX || left.second == INT_MAX) &&
          (right.first == INT_MAX || right.second == INT_MAX)) { // no left and no right
        to_zero = 0, to_one = 1;
      } else if (left.first != INT_MAX && left.second != INT_MAX &&
          right.first != INT_MAX && right.second != INT_MAX) { // has both left and right
        to_zero = min({left.first + right.first,
                       left.first + right.second + 1,
                       left.second + 1 + right.first,
                       left.second + 2 + right.second});
        to_one = min({left.first + right.first + 1,
                      left.first + right.second + 2,
                      left.second + left.first + 2,
                      left.second + right.second + 1});
      } else if (left.first != INT_MAX && left.second != INT_MAX) { // has only left
        to_zero = min(left.first, left.second + 1);
        to_one = min(left.first + 1, left.second + 1);
      } else { // has only right
        to_zero = min(right.first, right.second + 1);
        to_one = min(right.first + 1, right.second + 1);
      }
    } else { // to one
      if ((left.first == INT_MAX || left.second == INT_MAX) &&
          (right.first == INT_MAX || right.second == INT_MAX)) { // no left and no right
        to_zero = 1, to_one = 0;
      } else if (left.first != INT_MAX && left.second != INT_MAX &&
          right.first != INT_MAX && right.second != INT_MAX) { // has both left and right
        to_zero = min({left.first + right.first + 1,
                       left.first + right.second + 2,
                       left.second + right.first + 2,
                       left.second + right.second + 1});
        to_one = min({
                         left.first + right.first + 2,
                         left.first + right.second + 1,
                         left.second + right.first + 1,
                         left.second + right.second});
      } else if (left.first != INT_MAX && left.second != INT_MAX) { // has only left
        to_zero = min(left.first + 1, left.second + 1);
        to_one = min(left.first + 1, left.second);
      } else { // has only right
        to_zero = min(right.first + 1, right.second + 1);
        to_one = min(right.first + 1, right.second);
      }
    }

    return make_pair(to_zero, to_one);
  }

};

int main() {

  auto *root = new TreeNode(0, 1);
  root->right = new TreeNode(1, 1);
  root->right->right = new TreeNode(2, 0);
  root->right->left = new TreeNode(3, 0);
  root->right->left->left = new TreeNode(4, 1);
  root->right->left->left->left = new TreeNode(5, 0);

  std::cout << Solution().closeLampInTree(root);

  return 0;
}
