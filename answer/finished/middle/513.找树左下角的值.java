/*
 * @lc app=leetcode.cn id=513 lang=java
 *
 * [513] 找树左下角的值
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

[2,1,3]
[1,2,3,4,null,5,6,null,null,7]

*/

/* Method 1: DFS

    Time: O(n)
    Space: O(height(root))
*/
class Solution {

    private int res;

    private int maxLayer;

    public int findBottomLeftValue(TreeNode root) {
        if (root == null) throw new RuntimeException("No result!");
        res = root.val;
        maxLayer = 0;
        dfs(root, 0);
        return res;
    }

    private void dfs(TreeNode root, int layer) {
        if (root == null) return;
        if (root.left != null) dfs(root.left, layer + 1);
        if (layer > maxLayer) {
            res = root.val;
            maxLayer = layer;
        }
        if (root.right != null) dfs(root.right, layer + 1);
    }
}
// @lc code=end

