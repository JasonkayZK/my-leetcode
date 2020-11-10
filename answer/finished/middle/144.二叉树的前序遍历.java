import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=144 lang=java
 *
 * [144] 二叉树的前序遍历
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

/* Test Case:

[]
[1,null,2,3]  
[1,2,3]
[1,2,3,4,5]

*/

/* Method 1: DFS

    Time: O(n)
    Space: O(height(root))

class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>(1000);
        dfs(root, res);
        return res;
    }

    private void dfs(TreeNode root, List<Integer> res) {
        if (root == null) return;
        res.add(root.val);
        if (root.left != null) dfs(root.left, res);
        if (root.right != null) dfs(root.right, res);
    }
}
*/

/* Method 2: BFS

    Time: O(n)
    Space: O(height(root))
*/
class Solution {
    
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>(1000);
        if (root == null) return res;

        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        while (!s.isEmpty()) {
            TreeNode temp = s.pop();
            res.add(temp.val);
            if (temp.right != null) s.push(temp.right);
            if (temp.left != null) s.push(temp.left);
        }

        return res;
    }

}

// @lc code=end

