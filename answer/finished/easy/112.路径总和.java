
/*
 * @lc app=leetcode.cn id=112 lang=java
 *
 * [112] 路径总和
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
0
[]
1
[1]
1
[1]
0
[2]
1
[1,2]
2
[1,2]
3
[1,null,2]
2
[1,null,2]
3
[5,4,8,11,null,13,4,7,2,null,null,null,1]
22

*/

/* Method 1: DFS

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        
        sum -= root.val;
        if (root.left == null && root.right == null) return sum == 0;
        return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
    }

}

