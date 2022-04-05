#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p ,q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) return right;
        if (right == nullptr) return left;

        return root;
    }

};

int main() {

    return 0;
}
