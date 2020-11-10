/*
 * @lc app=leetcode.cn id=110 lang=java
 *
 * [110] 平衡二叉树
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * 
 */

/* Test Case:

[1]
[1,2]
[1,2,null]
[3,9,20,null,null,15,7]
[1,2,2,3,3,null,null,4,4]

*/

/* Method 1: Top to root

    Time: O(n)
    Space: O(1)

class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        return Math.abs(height(root.right) - height(root.left)) < 2 && isBalanced(root.left) && isBalanced(root.right); 
    }

    private int height(TreeNode root) {
        if (root == null) return 0;
        return Math.max(height(root.left), height(root.right)) + 1;
    }
}
*/

/* Method 2: Root to top

    Time: O(n)
    Space: O(1)
*/
class Solution {

    private boolean res = true;

    public boolean isBalanced(TreeNode root) {
        height(root);
        return res;
    }

    private int height(TreeNode root) {
        if (!res) return -1;
        if (root == null) return 0;
        int left = height(root.left) + 1;
        int right = height(root.right) + 1;
        if (Math.abs(right - left) > 1) res = false;
        return Math.max(left, right);
    }
}




