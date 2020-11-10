/*
 * @lc app=leetcode.cn id=543 lang=java
 *
 * [543] 二叉树的直径
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

/* Method 1: DFS: find depth

    Time: O(n)
    Space: O(1)
*/
class Solution {

    private int max = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        findDepth(root);
        return max;        
    }

    private int findDepth(TreeNode root) {
        if (root == null) return 0;
        int left = findDepth(root.left);
        int right = findDepth(root.right);

        max = Math.max(max, left + right);

        return Math.max(left, right) + 1;
    }
}

