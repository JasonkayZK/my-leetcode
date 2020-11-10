/*
 * @lc app=leetcode.cn id=965 lang=java
 *
 * [965] 单值二叉树
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

[1]
[1,1,1,1,1,null,1]
[2,2,2,5,2]

*/

/* Method 1: DFS 

    Time: O(n)
    Space: O(1)
*/
class Solution {

    public boolean isUnivalTree(TreeNode root) {
        if (root == null) return true;
        boolean left = true, right = true;

        if (root.left != null) {
            if (root.val != root.left.val) return false;
            left = isUnivalTree(root.left);
        }
        if (root.right != null) {
            if (root.val != root.right.val) return false;
            right = isUnivalTree(root.right);
        }

        return left && right;
    }

}

