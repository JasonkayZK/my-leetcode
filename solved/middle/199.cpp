#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method 1: BFS
class Solution {
private:

public:

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto cur = q.front();
                q.pop();

                if (cur->left != nullptr) {
                    q.emplace(cur->left);
                }
                if (cur->right != nullptr) {
                    q.emplace(cur->right);
                }
                if (i == n-1) {
                    res.push_back(cur->val);
                }
            }
        }

        return res;
    }
};
*/

/* Method 2: DFS */
class Solution {
 private:

  vector<int> res;

  void dfs_helper(TreeNode *root, int depth) {
    if (root == nullptr) return;

    if (depth == res.size()) {
      res.push_back(root->val);
    }
    depth++;
    dfs_helper(root->right, depth);
    dfs_helper(root->left, depth);
  }

 public:
  vector<int> rightSideView(TreeNode *root) {
    dfs_helper(root, 0);
    return res;
  }
};

int main() {

  return 0;
}
