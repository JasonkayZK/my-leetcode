import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=437 lang=java
 *
 * [437] 路径总和 III
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

/* Method 1: Generate Path:

    Time: O(n)
    Space: O(n)
*/
class Solution {

    private int res;

    public int pathSum(TreeNode root, int sum) {
        res = 0;
        List<Integer> data = new ArrayList<>();
        recursive(root, sum, data);
        return res;
    }

    private void recursive(TreeNode root, int sum, List<Integer> data) {
        if (root == null) return;
        data.add(root.val);
        int cur = 0;
        for (int i = data.size() - 1; i >= 0; --i) {
            cur += data.get(i);
            if (cur == sum) res++;
        }
        recursive(root.left, sum, data);
        recursive(root.right, sum, data);
        data.remove(data.size() - 1);
    }
}


