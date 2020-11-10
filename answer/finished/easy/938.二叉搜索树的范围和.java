/*
 * @lc app=leetcode.cn id=938 lang=java
 *
 * [938] 二叉搜索树的范围和
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

[10,5,15,3,7,null,18]
7
15
[10,5,15,3,7,13,18,1,null,6]
6
10

*/

/* Method 1: DFS: Traverse


    Time: O(N)
    Space: O(1)

class Solution {

    public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null) return 0;
        int left = rangeSumBST(root.left, L, R);
        if (root.val <= R && root.val >= L) left += root.val;
        return rangeSumBST(root.right, L, R) + left;
    }

}
*/

/* Method 2: DFS + 剪枝


    Time: < O(N)
    Space: O(1)
*/
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root == null) return 0;
        int res = 0;
        //减枝条件
        if(root.val > L){
            res+=rangeSumBST(root.left, L, R);
        }
        //减枝条件
        if(root.val < R){
            res+=rangeSumBST(root.right, L, R);
        }
        if(root.val>=L && root.val<=R){
            res+=root.val;
        }
        return res;
    }
}



