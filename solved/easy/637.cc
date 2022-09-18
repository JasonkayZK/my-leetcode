#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<double> averageOfLevels(TreeNode *root) {
    if (root == nullptr) return {};
    vector<double> res;
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
      int n = int(q.size());
      double cur_sum = 0.0;

      for (int i = 0; i < n; ++i) {
        auto *node = q.front();
        q.pop();

        cur_sum += node->val;
        if (node->left != nullptr) q.emplace(node->left);
        if (node->right != nullptr) q.emplace(node->right);
      }

      res.emplace_back(cur_sum / n);
    }

    return res;
  }

 private:

};

int main() {

  return 0;
}
