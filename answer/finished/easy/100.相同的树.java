import java.util.Stack;

/*
 * @lc app=leetcode.cn id=100 lang=java
 *
 * [100] 相同的树
 *
 * https://leetcode-cn.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (54.38%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    32.7K
 * Total Submissions: 60.2K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:      1          1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * 输出: false
 * 
 * 
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
[1]
[]
[1,2,1]
[1,1,2]
[1,2,3]
[1,2,3]

*/

/* Method 1: Recursive 

    Time Complexity: O(n): n = min(len(p), len(q))
    Space Complexity: O(1)

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if ((p == null && q != null) || (p != null && q == null) || (p != null && q != null && p.val != q.val)) {return false;}
        if (p == null && q == null) return true;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}

*/

/* Method 2: Iteration Method */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if ((p == null && q!= null) || (p != null && q == null)) return false;

        Stack<TreeNode> stackP = new Stack<>();
        Stack<TreeNode> stackQ = new Stack<>();
        stackP.push(p);
        stackQ.push(q);

        while (!stackP.isEmpty() && !stackQ.isEmpty()) {
            TreeNode temP = stackP.pop();
            TreeNode temQ = stackQ.pop();

            if (temP.val != temQ.val) return false;
            if (temP.left != null && temQ.left != null) {
                stackP.push(temP.left);
                stackQ.push(temQ.left);
            } else if (temP.left == null && temQ.left == null) {
                // do nothing!
            } else {
                return false;
            }
            if (temP.right != null && temQ.right != null) {
                stackP.push(temP.right);
                stackQ.push(temQ.right);
            } else if (temP.right == null && temQ.right == null) {
                // do nothing
            } else {
                return false;
            }
        }
        return (stackP.isEmpty() && stackQ.isEmpty());
    }
}

