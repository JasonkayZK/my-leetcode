import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=94 lang=java
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/* Method 1: dfs

    Time: O(n)
    Space: O(height(root)) n = count(root)

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>(10000);
        dfs(root, res);
        return res;
    }

    private void dfs(TreeNode root, List<Integer> res) {
        if (root == null) return;
        if (root.left != null) dfs(root.left, res);
        res.add(root.val);
        if (root.right != null) dfs(root.right, res);
    }

}
*/

/* Method 2: bfs: Stack

    Time: O(n)
    Space: O(weight(root)) n = count(root)
*/
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>(10000);
        if (root == null) return res;

        TreeNode cur = root;
        Stack<TreeNode> s = new Stack<>();
        while (cur != null || !s.isEmpty()) {
            while (cur != null) {
                s.push(cur);
                cur = cur.left;
            }
            cur = s.pop();
            res.add(cur.val);
            cur = cur.right;
        }

        return res;
    }
}



// @lc code=end

