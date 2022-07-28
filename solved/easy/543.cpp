#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  int ans;

  int depth(TreeNode *root) {
    if (root == nullptr) return 0;

    int L = depth(root->left);
    int R = depth(root->right);
    ans = max(ans, L + R + 1);
    return max(L, R) + 1;
  }

 public:

  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) return 0;
    ans = 0;
    depth(root);
    return ans - 1;
  }

};

int main() {

  return 0;
}
