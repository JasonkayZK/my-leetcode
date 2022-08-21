#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return build_tree(nums, 0, int(nums.size()) - 1);
  }

 private:

  TreeNode *build_tree(vector<int> &nums, int left, int right) {
    if (left < 0 || left > right) return nullptr;

    int index = -1, maxVal = INT_MIN;
    for (int i = left; i <= right; i++) {
      if (maxVal < nums[i]) {
        index = i;
        maxVal = nums[i];
      }
    }

    auto* root = new TreeNode(maxVal);
    // 递归调用构造左右子树
    root->left = build_tree(nums, left, index - 1);
    root->right = build_tree(nums, index + 1, right);

    return root;
  }

};

int main() {

  return 0;
}
