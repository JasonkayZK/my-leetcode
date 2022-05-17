#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

/* Solution 1: BST
class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (root == nullptr || p == nullptr) return nullptr;

        TreeNode *cur = root, *res = nullptr;
        while (cur != nullptr) {
            if (cur->val > p->val) {
                res = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return res;
    }
};
 */

/* Solution 2: BFS Method (in-order traversal) */
class Solution {
public:

    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (root == nullptr || p == nullptr) return nullptr;

        stack < TreeNode * > st;
        TreeNode *cur = root, *prev = nullptr;
        while (!st.empty() || cur != nullptr) {
            while (cur != nullptr) {
                st.emplace(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (prev == p) {
                return cur;
            }
            prev = cur;
            cur = cur->right;
        }

        return nullptr;
    }
};

int main() {

    auto *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    std::cout << Solution().inorderSuccessor(root, new TreeNode(1));

    return 0;
}
