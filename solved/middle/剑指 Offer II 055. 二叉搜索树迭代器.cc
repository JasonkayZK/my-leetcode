#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class BSTIterator {
 private:
  void inorder(TreeNode* root, vector<int>& res) {
    if (!root) {
      return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }

  vector<int> arr;
  int idx;
 public:
  BSTIterator(TreeNode* root): idx(0), arr(inorderTraversal(root)) {}

  int next() {
    return arr[idx++];
  }

  bool hasNext() {
    return (idx < arr.size());
  }
};

int main() {

  return 0;
}
