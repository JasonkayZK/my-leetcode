#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) return {};

        queue<TreeNode *> q{};
        q.push(root);
        vector<vector<int>> res;

        while (!q.empty()) {
            int n = int(q.size());
            auto cur_level = vector<int>();

            for (int i = 0; i < n; ++i) {
                TreeNode *cur = q.front();
                q.pop();

                cur_level.push_back(cur->val);
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }

            res.push_back(cur_level);
        }

        return res;
    }

};

int main() {

    return 0;
}
