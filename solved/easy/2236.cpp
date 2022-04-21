#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }

};

int main() {

    return 0;
}
