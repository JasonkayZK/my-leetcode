/*
 * @lc app=leetcode.cn id=530 lang=java
 *
 * [530] 二叉搜索树的最小绝对差
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

    private TreeNode pre;

    private int min = Integer.MAX_VALUE;

    public int getMinimumDifference(TreeNode root) {
        helper(root);
        return min;
    }

    private void helper(TreeNode root) {
        if (root == null) return;
        helper(root.left);
        if (pre != null) min = Math.min(min, root.val - pre.val);
        pre = root;
        helper(root.right);
    }


}

