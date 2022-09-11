#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<string> binaryTreePaths(TreeNode *root) {
    if (root == nullptr) return {};
    vector<string> res;
    dfs_helper(root, "", res);
    return res;
  }

 private:

  void dfs_helper(TreeNode *root, string path, vector<string> &paths) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
      path += to_string(root->val);
      paths.push_back(path);
      return;
    }

    dfs_helper(root->left, path + to_string(root->val) + "->", paths);
    dfs_helper(root->right, path + to_string(root->val) + "->", paths);
  }

};

int main() {

  return 0;
}
