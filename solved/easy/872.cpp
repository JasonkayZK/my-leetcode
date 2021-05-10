//
// Created by jasonkay on 2021/5/10.
//

#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        find_leaf(root1, res1);
        find_leaf(root2, res2);
        return res1 == res2;
    }

private:

    std::vector<int> res1;

    std::vector<int> res2;

    void find_leaf(TreeNode *root, std::vector<int> &res) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) res.emplace_back(root->val);
        if (root->left != nullptr) find_leaf(root->left, res);
        if (root->right != nullptr) find_leaf(root->right, res);
    }
};
