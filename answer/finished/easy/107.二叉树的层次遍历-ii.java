import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=107 lang=java
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (62.03%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 36.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
[1,2]
[1,2,null]
[1,null,2]
[1,2,2]
[1,2,2,1]
[1,2,2,3,4,4,3]
[1,2,2,null,3,null,3] 
[3,9,20,null,null,15,7]

*/

/* Method 1: Recursive 

    Time Complexity: O(n)
    Space Complexity: O(1) result space is not included!

class Solution {

    private List<List<Integer>> result;

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        result = new ArrayList<>();
        traversalTree(root, 0);
        Collections.reverse(result);
        return result;
    }

    private void traversalTree(TreeNode root, int level) {
        if (root == null) {return;}
        if (result.size() < level + 1) result.add(new ArrayList<>());
        
        result.get(level).add(root.val); 

        traversalTree(root.left, level + 1);
        traversalTree(root.right, level + 1);
    }
}
*/

/* Method 2: Queue: BFS

    Time Complexity: O(n)
    Space Complexity: O(n)

*/
class Solution {

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {return res;}
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < size; ++i) {
                TreeNode node = queue.poll();
                level.add(node.val);
                if (node.left != null) {queue.offer(node.left);}
                if (node.right != null) {queue.offer(node.right);}
            }
            res.add(level);
        }
        Collections.reverse(res);
        return res;
    }


}

