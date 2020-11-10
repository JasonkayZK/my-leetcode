/*
 * @lc app=leetcode.cn id=671 lang=java
 *
 * [671] 二叉树中第二小的节点
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


/* Test Case:



*/
/* Method 1: DFS: Force to stop

    Time: << O(n)
    Space: O(1)
*/
class Solution {

    public int findSecondMinimumValue(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return -1;
        
        int left = root.left.val;
        int right = root.right.val;

        if (left == root.val) left = findSecondMinimumValue(root.left);
        if (right == root.val) right = findSecondMinimumValue(root.right);

        if (left != -1 && right != -1) return Math.min(left, right);
        return left == -1 ? right : left;
    }
}

