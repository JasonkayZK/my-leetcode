/*
 * @lc app=leetcode.cn id=404 lang=java
 *
 * [404] 左叶子之和
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
[1,2,3,null,5]
[3,9,20,null,null,15,7]
[-9,-3,2,null,4,4,0,-6,null,-5]

*/

/* Method 1: DFS 

    Time: O(n)
    Space: O(1)
*/

class Solution {

    private int sum;

    public int sumOfLeftLeaves(TreeNode root) {
        sum = 0;
        sumLeft(root);
        return sum;
    }

    private void sumLeft(TreeNode root) {
        if (root == null) return;
        if (root.left != null && root.left.left == null && root.left.right == null) sum += root.left.val;
        sumLeft(root.left);
        sumLeft(root.right);
    }
}

