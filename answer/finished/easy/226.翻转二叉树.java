/*
 * @lc app=leetcode.cn id=226 lang=java
 *
 * [226] 翻转二叉树
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

[]
[1]
[1,2]
[1,null,2]
[4,2,7,1,3,6,9]

*/

/* Method 1: DFS: Top to Root

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        TreeNode swap = invertTree(root.left);
        root.left = invertTree(root.right);
        root.right = swap;
        return root;
    }
}

