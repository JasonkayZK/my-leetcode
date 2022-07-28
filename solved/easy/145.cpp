#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) return res;

    stack < TreeNode * > stk;
    auto prev = root;
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        stk.emplace(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      if (root->right == nullptr || root->right == prev) {
        res.emplace_back(root->val);
        prev = root;
        root = nullptr;
      } else {
        stk.emplace(root);
        root = root->right;
      }
    }

    return res;
  }

};

int main() {

  return 0;
}
