/*
 * @lc app=leetcode.cn id=563 lang=java
 *
 * [563] 二叉树的坡度
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
[1,2,3,4]
[1,2,3,4,null,5]

*/

/* Method 1: DFS 

    Time: O(n)
    Space: O(1)
*/
class Solution {

    private int res = 0;

    public int findTilt(TreeNode root) {
        sumTilt(root);
        return res;
    }

    private int sumTilt(TreeNode root) {
        if (root == null) return 0;
        int l = sumTilt(root.left);
        int r = sumTilt(root.right);

        res += Math.abs(l - r);
        return l + r + root.val;
    }
}

