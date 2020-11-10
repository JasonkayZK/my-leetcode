/*
 * @lc app=leetcode.cn id=572 lang=java
 *
 * [572] 另一个树的子树
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

[3,4,5,1,2]
[4,1,2]
[1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,2]
[1,null,1,null,1,null,1,null,1,null,1,2]

*/
/* Method 1: DFS: Brute Force

    Time: O(m * n)
    Space: O(n)
*/
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        boolean flag = false;
        if (s != null && t != null) {
            if (s.val == t.val) flag = isSame(s, t);
            flag = flag || isSubtree(s.left, t) || isSubtree(s.right, t);
        }
        return flag;
    }

    private boolean isSame(TreeNode src, TreeNode target) {
        if (src == null && target == null) return true;
        if (src == null || target == null) return false;
        if (src.val != target.val) return false;
        return isSame(src.left, target.left) && isSame(src.right, target.right);
    }
}

