/*
 * @lc app=leetcode.cn id=1022 lang=java
 *
 * [1022] 从根到叶的二进制数之和
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

/* Method 1: DFS

    Time: O(n)
    Space: O(1)
*/
class Solution {

    private static int res = 0;

    public int sumRootToLeaf(TreeNode root) {
        res = 0;
        dfs(root, 0);
        return res;
    }

    private void dfs(TreeNode root, int curNum) {
        if (root == null) return;
        
        curNum = curNum << 1 | root.val;
        if (root.left == null && root.right == null) {
            res += curNum % (1000000007);
            res %= 1000000007;
            return;
        }
        if (root.left != null) dfs(root.left, curNum);
        if (root.right != null) dfs(root.right, curNum);
    }
}

