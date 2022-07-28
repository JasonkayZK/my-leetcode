#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int averageOfSubtree(TreeNode *root) {
    res = 0;
    calculate_sum(root);
    return res;
  }

 private:

  pair<int, int> calculate_sum(TreeNode *cur) {
    if (cur == nullptr) {
      return make_pair(0, 0);
    }

    pair<int, int> left = calculate_sum(cur->left);
    pair<int, int> right = calculate_sum(cur->right);

    int sum_node_cnt = 1 + left.first + right.first;
    int sum_val = cur->val + left.second + right.second;
    if (sum_val / sum_node_cnt == cur->val) res++;
    return make_pair(sum_node_cnt, sum_val);
  }

  int res;
};
