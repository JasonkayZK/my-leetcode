import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=257 lang=java
 *
 * [257] 二叉树的所有路径
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
[1,null,2]
[1,2,3,null,5]

*/


/* Method 1: DFS 

    Time: O(n)
    Space: O(1)
*/
class Solution {

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        buildPath(root, "", res);
        return res;
    }

    private void buildPath(TreeNode root, String path, List<String> res) {
        if (root != null) {
            path += Integer.toString(root.val);
            if (root.left == null && root.right == null) {
                res.add(path);
            } else {
                path += "->";
                buildPath(root.left, path, res);
                buildPath(root.right, path, res);
            }
        }
    }

}

