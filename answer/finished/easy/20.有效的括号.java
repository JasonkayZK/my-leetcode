/*
 * @lc app=leetcode.cn id=20 lang=java
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.29%)
 * Likes:    986
 * Dislikes: 0
 * Total Accepted:    109K
 * Total Submissions: 277.5K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

/* Test case:
    "()[]{}"
    ""
    "([)]"
*/

/* Method 1:  Stack */

class Solution {

    public boolean isValid(String s) {
        if (s == null || s == "") {return true;}

        Stack<Character> stack = new Stack<>();    
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.size() == 0) {return false;}
                if ((c == ')' && stack.peek() == '(') || (c == ']' && stack.peek() == '[') || (c == '}' && stack.peek() == '{')) {
                    stack.pop();                    
                } else {
                    return false;
                }
            }
        }
        return stack.size() == 0;
    }
}


/* Method 2: [Bad] Replace string 
class Solution {

    public boolean isValid(String s) {
        int length = 0;

        do {
            length = s.length();
            s = s.replace("()", "").replace("[]", "").replace("{}", "");
        } while (length != s.length());
        
        return s.length() == 0;
    }
}
*/
