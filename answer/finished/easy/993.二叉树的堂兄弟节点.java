/*
 * @lc app=leetcode.cn id=993 lang=java
 *
 * [993] 二叉树的堂兄弟节点
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

[1,2,3,4]
4
3
[1,2,3,null,4,null,5]
5
4
[1,2,3,null,4]
2
3

*/

/* Method 1: Brute force

    Time: < 2 * O(height(root))
    Space: O(1)
*/
class Solution {

    class FatherAndLayer {
        public int layer;
        public int father;

        FatherAndLayer() {}

        FatherAndLayer(int layer, int father) {
            this.layer = layer;
            this.father = father;
        }
    }

    public boolean isCousins(TreeNode root, int x, int y) {
        FatherAndLayer xFather = findFatherAndLayer(root, null, 0, x);
        FatherAndLayer yFather = findFatherAndLayer(root, null, 0, y);
        
        return xFather.father != yFather.father && xFather.layer == yFather.layer;
    }

    private FatherAndLayer findFatherAndLayer(TreeNode root, TreeNode pre, int layer, int x) {
        if (root == null) return null;
        if (root.val == x) {
            if (pre == null) return new FatherAndLayer(layer, 0);
            else return new FatherAndLayer(layer, pre.val);
        }

        FatherAndLayer left = findFatherAndLayer(root.left, root, layer + 1, x);
        FatherAndLayer right = findFatherAndLayer(root.right, root, layer + 1, x);
        return left == null ? right : left;
    }

}
// @lc code=end

