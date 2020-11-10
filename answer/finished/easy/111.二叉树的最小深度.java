/*
 * @lc app=leetcode.cn id=111 lang=java
 *
 * [111] 二叉树的最小深度
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

/* Test Case

[]
[1]
[1,2, null]
[1,null,2]
[3,9,20,null,null,15,7]

*/

/* Method 1: Top to Root

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        
        int left = minDepth(root.left), right = minDepth(root.right);
        return (left != 0 && right != 0) ? 1 + Math.min(left, right) : 1 + left + right;
    }
}
    
