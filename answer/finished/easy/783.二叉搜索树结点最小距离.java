/*
 * @lc app=leetcode.cn id=783 lang=java
 *
 * [783] 二叉搜索树结点最小距离
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

[4,2,6,1,3,null,null]
[90,69,null,49,89,null,52,null,null,null,null]

*/
/* Method 1: DFS: Inorder


    Time: O(n)
    Space: O(height(root))
*/
class Solution {

    int min = Integer.MAX_VALUE;
    TreeNode pre = null;

    public int minDiffInBST(TreeNode root) {
        help(root);
        return min;
    }
    
    private void help(TreeNode root) {
        if(root == null) return;
        
        help(root.left);
        if(pre != null) min = Math.min(root.val - pre.val, min);
        pre = root;
        help(root.right);
    }

}

