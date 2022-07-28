#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

using namespace std;

// Definition for a binary tree node.
class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  int x_father = 0;
  int x_depth = 0;
  int y_father = 0;
  int y_depth = 0;

  void findFather(TreeNode *root, int x, int y, TreeNode *father, int level) {
    if ((!root) || (x_father > 0 && y_father > 0)) {
      return;
    }

    if (root->val == x) {
      tie(x_father, x_depth) = tuple{father->val, level};
    } else if (root->val == y) {
      tie(y_father, y_depth) = tuple{father->val, level};
    }

    if (x_father > 0 && y_father > 0) {
      return;
    }

    findFather(root->left, x, y, root, level + 1);
    if (x_father > 0 && y_father > 0) {
      return;
    }
    findFather(root->right, x, y, root, level + 1);
  }

 public:

  bool isCousins(TreeNode *root, int x, int y) {
    if (root->val == x || root->val == y) {
      return false;
    }

    this->x_father = 0;
    this->y_father = 0;
    this->x_depth = 0;
    this->y_depth = 0;

    findFather(root, x, y, nullptr, 0);

    return (this->x_depth == this->y_depth) && (this->x_father != this->y_father);
  }
};

int main() {

  return 0;
}
