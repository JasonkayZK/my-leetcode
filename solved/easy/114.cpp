#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                res.emplace_back(root->val);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            root = root->right;
        }

        return res;
    }

};

int main() {


    return 0;
}
