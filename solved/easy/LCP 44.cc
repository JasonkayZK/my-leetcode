#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int numColor(TreeNode *root) {
    queue<TreeNode *> q;
    unordered_set<int> s;
    q.emplace(root);
    while (!q.empty()) {
      int n = int(q.size());

      for (int i = 0; i < n; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        s.emplace(cur->val);
        if (cur->left != nullptr) q.emplace(cur->left);
        if (cur->right != nullptr) q.emplace(cur->right);
      }
    }

    return int(s.size());
  }

 private:

};

int main() {

  return 0;
}
