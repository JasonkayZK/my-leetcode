/*
 * @lc app=leetcode.cn id=687 lang=java
 *
 * [687] 最长同值路径
 */

// @lc code=start
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

/* Method 1: DFS 

    Time: O(n)
    Space: O(height)
*/
class Solution {

    private static int max;

    public int longestUnivaluePath(TreeNode root) {
        max = 0;
        helper(root);
        return max;
    }

    private int helper(TreeNode root) {
        if (root == null) return 0;
        
        int left = helper(root.left);
        int right = helper(root.right);
        int deepLeft = 0, deepRight = 0;
        if (root.left != null && root.left.val == root.val) deepLeft = left + 1;
        if (root.right != null && root.right.val == root.val) deepRight = right + 1;

        max = Math.max(max, deepLeft + deepRight);
        return Math.max(deepLeft, deepRight);
    }

}
// @lc code=end


