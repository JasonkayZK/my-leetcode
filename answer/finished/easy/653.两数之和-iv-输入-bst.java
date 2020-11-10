/*
 * @lc app=leetcode.cn id=653 lang=java
 *
 * [653] 两数之和 IV - 输入 BST
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

*/

/* Method 1: Two Pointer: Create Ordered-Array by Tree

    Time: O(n)
    Space: O(n)
*/
class Solution {
    
    List<Integer> list = new ArrayList<Integer>();

    public boolean findTarget(TreeNode root, int k) {
        inOrder(root);
        int head = 0;
        int tail = list.size() - 1;
        while(head < tail) {
            if(list.get(head) + list.get(tail) == k) {
                return true;
            }
            if(list.get(head) + list.get(tail) < k) {
                head++;
            }
            if(list.get(head) + list.get(tail) > k) {
                tail--;
            }
        }
        return false;
    }
    public void inOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        inOrder(root.left);
        list.add(root.val);
        inOrder(root.right);
    }

}
// @lc code=end

