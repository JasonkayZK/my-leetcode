/*
 * @lc app=leetcode.cn id=559 lang=java
 *
 * [559] N叉树的最大深度
 */
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

/* Test Case:

{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}

*/

/* Method 1:

    Time: O(n)
    Space: O(height(root))
*/
class Solution {
    public int maxDepth(Node root) {
        if (root == null) return 0;
        if (root.children == null) return 1;
        int childrenMax = 0;
        for (int i = 0; i < root.children.size(); ++i) {
            childrenMax = Math.max(maxDepth(root.children.get(i)), childrenMax);
        }        
        return childrenMax + 1;
    }
}

