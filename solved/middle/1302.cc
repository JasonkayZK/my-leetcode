#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int deepestLeavesSum(TreeNode *root) {
    if (root == nullptr) return 0;

    int res = 0;
    vector<TreeNode *> level = vector{root};
    while (true) {
      if (level.empty()) break;
      vector<TreeNode *> cur_level{};
      res = 0;
      for (const auto &item : level) {
        res += item->val;
        if (item->left != nullptr) cur_level.push_back(item->left);
        if (item->right != nullptr) cur_level.push_back(item->right);
      }
      level = cur_level;
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
