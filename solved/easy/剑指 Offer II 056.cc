#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  unordered_set<int> hashTable;

  bool findTarget(TreeNode *root, int k) {
    if (root == nullptr) {
      return false;
    }
    if (hashTable.count(k - root->val)) {
      return true;
    }
    hashTable.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
  }

 private:

};

int main() {



  return 0;
}
