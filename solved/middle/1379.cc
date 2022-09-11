#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
    if (original == target) return cloned;
    deque<bool> paths;
    found = false;
    find_paths(original, target, paths);
    return get_target(cloned, paths);
  }

 private:

  void find_paths(TreeNode *original, const TreeNode *target, deque<bool> &paths) {
    if (original == nullptr || found) return;
    if (original == target) {
      found = true;
      return;
    }

    paths.push_back(true);
    find_paths(original->left, target, paths);
    if (!found) {
      paths.pop_back();
    } else {
      return;
    }

    paths.push_back(false);
    find_paths(original->right, target, paths);
    if (!found) {
      paths.pop_back();
    } else {
      return;
    }
  }

  static TreeNode *get_target(TreeNode *cloned, const deque<bool> &paths) {
    for (const auto &item : paths) {
      if (item) cloned = cloned->left;
      else cloned = cloned->right;
    }
    return cloned;
  }

  bool found;

};

int main() {

  return 0;
}
