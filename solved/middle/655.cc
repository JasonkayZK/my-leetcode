#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<vector<string>> printTree(TreeNode *root) {
    int height = findDepth(root) - 1;
    int m = height + 1, n = (1 << (height + 1)) - 1;
    vector<vector<string>> res = vector(m, vector<string>(n, ""));
    int r = 0, c = (n - 1) / 2;
    helper(root, res, r, c, height);
    return res;
  }

 private:

  int findDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    return max(findDepth(root->left), findDepth(root->right)) + 1;
  }

  void helper(TreeNode *cur, vector<vector<string>> &res, int r, int c, const int height) {
    if (cur == nullptr) return;
    res[r][c] = to_string(cur->val);

    if (cur->left != nullptr) helper(cur->left, res, r + 1, c - (1 << (height - r - 1)), height);
    if (cur->right != nullptr) helper(cur->right, res, r + 1, c + (1 << (height - r - 1)), height);
  }

};

int main() {

  auto *root = new TreeNode(1);
  root->left = new TreeNode(2);
  cout << Solution().printTree(root);

  return 0;
}
