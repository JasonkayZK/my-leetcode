import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=872 lang=java
 *
 * [872] 叶子相似的树
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

[1]
[2]
[1]
[1]
[3,5,1,6,2,9,8,null,null,7,4]
[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]

*/

/* Method 1: build Leaf 

    Time: O(n + m)
    Space: O(log(n) + log(m))
*/
class Solution {

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leaf1 = new ArrayList<>();
        List<Integer> leaf2 = new ArrayList<>();
        
        findLeaf(leaf1, root1);
        findLeaf(leaf2, root2);

        if (leaf1.size() != leaf2.size()) return false;
        for (int i = 0; i < leaf1.size(); ++i) {
            if (leaf1.get(i) != leaf2.get(i)) return false;
        }
        return true;
    }

    private void findLeaf(List<Integer> leaf, TreeNode root) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            leaf.add(root.val);
        }
        if (root.left != null) findLeaf(leaf, root.left);
        if (root.right != null) findLeaf(leaf, root.right);
    }
}

