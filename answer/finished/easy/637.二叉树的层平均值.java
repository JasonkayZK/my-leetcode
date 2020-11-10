import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=637 lang=java
 *
 * [637] 二叉树的层平均值
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



*/

/* Method 1: BFS 

    Time: O(n)
    Space: O(max(layer_node_number))
*/
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<>(100);
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        int len = q.size(), cur = 0;
        double sum = 0.0;
        while (!q.isEmpty()) {
            len = q.size();
            cur = 0;
            sum = 0.0;

            while (cur < len) {
                TreeNode temp = q.poll();
                sum += temp.val;
                if (temp.left != null) q.offer(temp.left);
                if (temp.right != null) q.offer(temp.right); 
                cur++;
            }
            res.add(sum / len);
        }
        return res;
    }
}
// @lc code=end

