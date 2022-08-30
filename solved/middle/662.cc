#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {

  struct NodePair {
    unsigned long long id;
    TreeNode *node;

    NodePair(unsigned long long id, TreeNode *node) : id(id), node(node) {}
  };

 public:

  int widthOfBinaryTree(TreeNode *root) {
    if (root == nullptr) return 0;

    unsigned long long res = 0;
    queue<NodePair> layer;
    layer.push(NodePair(1, root));
    while (!layer.empty()) {
      unsigned long long cur_cnt = layer.size(), l = 0, r = 0;
      for (unsigned long long i = 0; i < cur_cnt; ++i) {
        auto cur_node = layer.front();
        layer.pop();

        if (i == 0) { // most left node
          l = cur_node.id;
        }
        if (i == cur_cnt - 1) { // most right node
          r = cur_node.id;
        }

        if (cur_node.node->left != nullptr) {
          layer.push(NodePair(cur_node.id * 2, cur_node.node->left));
        }
        if (cur_node.node->right != nullptr) {
          layer.push(NodePair(cur_node.id * 2 + 1, cur_node.node->right));
        }
      }
      res = max(res, r - l + 1);
    }
    return int(res);
  }

 private:

};

int main() {

  cout << Solution().widthOfBinaryTree(new TreeNode(1));

  return 0;
}
