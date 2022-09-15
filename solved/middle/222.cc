#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int countNodes(TreeNode *root) {
    if (root == nullptr) return 0;

    int level = 0;
    TreeNode *node = root;
    while (node->left != nullptr) {
      ++level;
      node = node->left;
    }

    int low = 1 << level, high = (1 << (level + 1)) - 1;
    while (low < high) {
      int mid = (high - low + 1) / 2 + low;
      if (exists(root, level, mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }

 private:

  static bool exists(TreeNode *root, int level, int x) {
    int bits = 1 << (level - 1);
    TreeNode *node = root;
    while (node != nullptr && bits > 0) {
      if (!(bits & x)) {
        node = node->left;
      } else {
        node = node->right;
      }
      bits >>= 1;
    }
    return node != nullptr;
  }

};

int main() {

  return 0;
}
