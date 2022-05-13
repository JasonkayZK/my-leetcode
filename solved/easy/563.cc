#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int findTilt(TreeNode *root) {
        res = 0;
        count_node(root);
        return res;
    }

private:

    int count_node(TreeNode *root) {
        if (root == nullptr) return 0;

        int left = count_node(root->left);
        int right = count_node(root->right);

        res += abs(right - left);

        return left + right + root->val;
    }

    int res;
};

int main() {


    return 0;
}
