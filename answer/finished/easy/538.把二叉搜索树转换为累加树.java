/*
 * @lc app=leetcode.cn id=538 lang=java
 *
 * [538] 把二叉搜索树转换为累加树
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    private int addfix = 0;

    public TreeNode convertBST(TreeNode root) {
        if (root == null) return root;
        postOrder(root);
        return root;        
    }

    private void postOrder(TreeNode root) {
        if (root == null) return;
        postOrder(root.right);
        root.val += addfix;
        addfix = root.val;
        postOrder(root.left);
    }
}

