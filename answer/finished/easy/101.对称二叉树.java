import java.util.Stack;

/*
 * @lc app=leetcode.cn id=101 lang=java
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (48.09%)
 * Likes:    414
 * Dislikes: 0
 * Total Accepted:    48.7K
 * Total Submissions: 101.2K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
[1,2]
[1,2,null]
[1,null,2]
[1,2,2]
[1,2,2,1]
[1,2,2,3,4,4,3]
[1,2,2,null,3,null,3] 

 */

 /* Method 1: Recursion 

    Time Complexity: O(n)
    Space Complexity: O(1)

class Solution {
    public boolean isSymmetric(TreeNode root) {
        return sameTree(root, root);
    }

    private boolean sameTree(TreeNode head1, TreeNode head2) {
        if (head1 == null && head2 == null) return true;
        if ((head1.val != head2.val) 
            || (head1.left == null && head2.right != null)
            || (head1.left != null && head2.right == null)
            || (head1.right == null && head2.left != null)
            || (head1.right != null && head2.left == null)) {return false;}
        return sameTree(head1.left, head2.right) && sameTree(head1.right, head2.left);
    }
}

*/

/* Method 2: Iteration 

    Time Complexity: O(n)
    Space Complexity: O(2n)
*/

class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) {return true;}

        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(root);
        stack2.push(root);
        while(!stack1.isEmpty() && !stack2.isEmpty()) {
            TreeNode tem1 = stack1.pop();
            TreeNode tem2 = stack2.pop();

            if (tem1.val != tem2.val) {return false;}
            if (tem1.left != null && tem2.right != null) {
                stack1.push(tem1.left);
                stack2.push(tem2.right);
            } else if (tem1.left == null && tem2.right == null) {

            } else {
                return false;
            }
            if (tem1.right != null && tem2.left != null) {
                stack1.push(tem1.right);
                stack2.push(tem2.left);
            } else if (tem1.right == null && tem2.left == null) {

            } else {
                return false;
            }
        }
        return (stack1.isEmpty() && stack2.isEmpty());
    }

}
