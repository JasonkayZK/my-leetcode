/*
 * @lc app=leetcode.cn id=114 lang=java
 *
 * [114] 二叉树展开为链表
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
[1, 2]
[1, null, 2]
[1,2,5,3,4,null,6]

*/

// @lc code=start
/* Method 1: BFS[Bad]

    Time: O(n)
    Space: O(height(root))

class Solution {
    public void flatten(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;

        while (cur != null || !stack.empty()) {
            if (cur.right != null) stack.push(cur.right);
            cur.right = cur.left;
            cur.left = null;

            if (!stack.isEmpty()) {
                if (cur == null) {
                    cur = stack.pop();
                } else if (cur.left == null && cur.right == null) {
                    cur.right = stack.pop();
                    
                }
            }
            cur = cur.right;
        }
    }
}
*/

/* Method 2: Recursive

    Time: O(n)
    Space: O(height(root))
*/
class Solution {

    private TreeNode pre = null;

    public void flatten(TreeNode root) {
        if (root == null) return;
        flatten(root.right);
        flatten(root.left);
        root.right = pre;
        root.left = null;

        pre = root;
    }
}


// @lc code=end

