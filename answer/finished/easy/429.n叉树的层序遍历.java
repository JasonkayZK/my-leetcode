import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=429 lang=java
 *
 * [429] N叉树的层序遍历
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



*/

/* Method 1: BFS (Iteration)

    Time: O(n)
    Space: O(n)

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int count = q.size();
            List<Integer> layer = new ArrayList<>();
            while (count-- > 0) {
                Node cur = q.poll();
                layer.add(cur.val);
                for (Node n : cur.children) {
                    q.add(n);
                }
            }
            res.add(layer);
        }
        return res;
    }
}
*/

/* Method 2: DFS (Recursion)

    Time: O(n)
    Space: > O(n)
*/
class Solution {

    private List<List<Integer>> res;

    public List<List<Integer>> levelOrder(Node root) {
        res = new ArrayList<>();
        helper(root, 0);
        return res;
    }

    private void helper(Node root, int depth) {
        if (root == null) return;
        if (depth > res.size() - 1) res.add(new ArrayList<>());
        res.get(depth).add(root.val);

        for (Node n : root.children) {
            if (n != null) {
                helper(n, depth + 1);
            }
        }
    }

}





