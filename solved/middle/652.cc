#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<string, TreeNode *> seen{};
    unordered_set<TreeNode *> res{};
    dfs_helper(root, seen, res);
    return {res.begin(), res.end()};
  }

  string dfs_helper(TreeNode *root, unordered_map<string, TreeNode *> &seen,
                    unordered_set<TreeNode *> &res) {

    if (root == nullptr) return "";

    string serial = to_string(root->val) +
        "(" + dfs_helper(root->left, seen, res) + ")(" +
        dfs_helper(root->right, seen, res) + ")";

    if (auto it = seen.find(serial); it != seen.end()) {
      res.insert(it->second);
    } else {
      seen[serial] = root;
    }

    return serial;
  }

 private:

};

int main() {

  return 0;
}
