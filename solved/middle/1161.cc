#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxLevelSum(TreeNode *root) {
    int res = 1, maxSum = root->val;
    vector < TreeNode * > q{root};
    for (int level = 1; !q.empty(); ++level) {
      vector < TreeNode * > nq;
      int sum = 0;
      for (auto node : q) {
        sum += node->val;
        if (node->left) {
          nq.emplace_back(node->left);
        }
        if (node->right) {
          nq.emplace_back(node->right);
        }
      }
      if (sum > maxSum) {
        maxSum = sum;
        res = level;
      }
      q = std::move(nq);
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
