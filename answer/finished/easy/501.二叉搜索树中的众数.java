import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=501 lang=java
 *
 * [501] 二叉搜索树中的众数
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

[1,null,2,2]

*/

/* Method 1: Brute Force: HashMap

    Time: O(2n)
    Space: > (n)

class Solution {
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> map = new HashMap<>();
        buildMap(root, map);
        List<Integer> res = new ArrayList<>();
        int max = 0, maxNum = 0;
        for (int key : map.keySet()) {
            int cur = map.get(key);
            if (cur > max) {
                max = cur;
                res.clear();
                res.add(key);
            } else if (cur == max) {
                res.add(key);
            }
        }

        int[] resArr = new int[res.size()];
        for (int i = 0; i < res.size(); ++i) {
            resArr[i] = res.get(i);
        } 
        return resArr;
    }

    private void buildMap(TreeNode root, Map<Integer, Integer> map) {
        if (root == null) return;
        map.put(root.val, map.getOrDefault(root.val, 0) + 1);
        buildMap(root.left, map);
        buildMap(root.right, map);
    }
}
*/

/* Method 2: Find in place 


    Time: O(n)
    Space: O(1)
*/
class Solution {
    private List<Integer> res;
    private TreeNode pre;
    private int max = 0;
    private int cur = 1;

    public int[] findMode(TreeNode root) {
        if (root == null) return new int[0];
        res = new ArrayList<>();
        findMost(root);

        int[] resArr = new int[res.size()];
        for (int i = 0; i < res.size(); ++i) {
            resArr[i] = res.get(i);
        }
        return resArr;
    }

    private void findMost(TreeNode root) {
        if (root == null) return;
        findMost(root.left);
        
        if (pre != null) {
            if (pre.val == root.val) {
                cur++;
            } else {
                cur = 1;
            }
        }
        if (cur == max) {
            res.add(root.val);
        } else if (cur > max) {
            res.clear();
            res.add(root.val);
            max = cur;
        }

        pre = root;
        findMost(root.right);
    }
}


