#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:

  vector<int> preorder(Node *root) {
    vector<int> res;
    dfs_helper(res, root);
    return res;
  }

 private:

  void dfs_helper(vector<int> &res, Node *root) {
    if (root == nullptr) return;
    res.push_back(root->val);
    for (auto & i : root->children) {
      dfs_helper(res, i);
    }
  }

};

int main() {

  return 0;
}
