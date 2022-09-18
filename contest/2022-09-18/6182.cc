#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  TreeNode *reverseOddLevels(TreeNode *root) {
    if (root == nullptr) return nullptr;
    queue<TreeNode *> q;
    q.emplace(root);
    bool level = false;
    queue<TreeNode *> level_nodes; // 维护另一个Queue来存储奇数级别的节点
    stack<int> level_data; // 维护一个Stack来存储节点的奇数层数据

    while (!q.empty()) {
      int n = int(q.size());
      while (n--) { // run each level
        TreeNode *curr = q.front();
        q.pop();

        // is odd level
        if (level) {
          level_nodes.push(curr);
          level_data.push(curr->val);
        }

        // the last node in this level
        if (n == 0) {
          level = !level;
          // 将 `level_data` 中的元素放入正确的位置
          // 使用 `level_nodes` 定位
          while (!level_nodes.empty()) {
            TreeNode *front = level_nodes.front();
            front->val = level_data.top();

            level_nodes.pop();
            level_data.pop();
          }
        }

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }

    return root;
  }

 private:

};

int main() {

  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(13);
  root->right = new TreeNode(11);

  Solution().reverseOddLevels(root);

  return 0;
}
