import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=102 lang=java
 *
 * [102] 二叉树的层次遍历
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
[1]
[1,2]
[1,null,2]
[3,9,20,null,null,15,7]

*/

/* Method 1: BFS 

    Time: O(n)
    Extra Space: O(max(layer_number))
*/
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>(1000);
        if (root == null) return res;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            int i = 0;
            List<Integer> layer = new ArrayList<>();

            while (i < size) {
                TreeNode cur = q.poll();
                layer.add(cur.val);
                if (cur.left != null) q.offer(cur.left);
                if (cur.right != null) q.offer(cur.right);
                ++i;
            }
            res.add(layer);
        }

        return res;
    }
}
// @lc code=end

