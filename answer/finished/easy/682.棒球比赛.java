import java.util.Stack;

/*
 * @lc app=leetcode.cn id=682 lang=java
 *
 * [682] 棒球比赛
 */

/* Test Case:

["5","2","C","D","+"]
["5","-2","4","C","D","9","+","+"]

*/

/* Method 1: Stack

    Time: O(n)
    Space: < O(n)
*/

// @lc code=start
class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> stack = new Stack<>();
        int res = 0;
        
        for (String op : ops) {
            if ("C".equals(op)) {
                res -= stack.pop();
            } else if ("D".equals(op)) {
                stack.push(stack.peek() * 2);
                res += stack.peek();
            } else if ("+".equals(op)) {
                int top = stack.pop();
                int sum = top + stack.peek();
                res += sum;
                stack.push(top);
                stack.push(sum);
            } else {
                int n = Integer.parseInt(op);
                res += n;
                stack.push(n);
            }
        }

        return res;
    }
}
// @lc code=end

