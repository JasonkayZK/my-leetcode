#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int findBottomLeftValue(TreeNode *root) {
    if (root == nullptr) return 0;
    queue<TreeNode *> q;
    q.emplace(root);
    int res = 0;
    while (!q.empty()) {
      int n = int(q.size());
      for (int i = 0; i < n; ++i) {
        auto *cur = q.front();
        q.pop();

        if (cur->right != nullptr) q.emplace(cur->right);
        if (cur->left != nullptr) q.emplace(cur->left);

        if (i == n - 1) res = cur->val;
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
