#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) return root;
        if (val < root->val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }

};

int main() {

    return 0;
}
