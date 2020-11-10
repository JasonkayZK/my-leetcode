/*
 * @lc app=leetcode.cn id=606 lang=java
 *
 * [606] 根据二叉树创建字符串
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

[1,2,3,4]
[1,2,3,null,4]

*/

/* Method 1: Recursive

    Time: O(n)
    Space: O(height(root))
*/
class Solution {
    public String tree2str(TreeNode t) {
        if (t == null) return "";
        if (t.left == null && t.right == null) return t.val+"";
        if (t.right == null) return t.val+"("+tree2str(t.left)+")";
        return t.val + "(" + tree2str(t.left) + ")(" + tree2str(t.right) + ")";
    }
}

