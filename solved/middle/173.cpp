#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
private:

public:


};

class BSTIterator {
private:
    TreeNode *cur;
    stack<TreeNode *> stk;
public:
    explicit BSTIterator(TreeNode *root) : cur(root) {};

    int next() {
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        int ret = cur->val;
        cur = cur->right;
        return ret;
    }

    bool hasNext() {
        return cur != nullptr || !stk.empty();
    }
};

int main() {


    return 0;
}
