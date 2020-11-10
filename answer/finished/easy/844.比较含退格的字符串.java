import java.util.Stack;

/*
 * @lc app=leetcode.cn id=844 lang=java
 *
 * [844] 比较含退格的字符串
 *
 * https://leetcode-cn.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (48.08%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 17.4K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：S = "ab#c", T = "ad#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “ac”。
 * 
 * 
 * 示例 2：
 * 
 * 输入：S = "ab##", T = "c#d#"
 * 输出：true
 * 解释：S 和 T 都会变成 “”。
 * 
 * 
 * 示例 3：
 * 
 * 输入：S = "a##c", T = "#a#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “c”。
 * 
 * 
 * 示例 4：
 * 
 * 输入：S = "a#c", T = "b"
 * 输出：false
 * 解释：S 会变成 “c”，但 T 仍然是 “b”。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S 和 T 只含有小写字母以及字符 '#'。
 * 
 * 
 * 
 * 
 */

/* Test Case:

"ab#c"
"ad#c"
"ab##"
"c#d#"
"a##c"
"#a#c"
"a#c"
"b"
"y#fo##f"
"y#f#o##f"

*/

/* Method 1: Stack 

    Time: O(m + n)
    Space: O(m + n)
*/
class Solution {
    public boolean backspaceCompare(String S, String T) {
        Stack<Character> stackS = new Stack<>();
        Stack<Character> stackT = new Stack<>();

        for (char c : S.toCharArray()) {
            if (c == '#') {
                if (!stackS.isEmpty()) stackS.pop();
            }
            else stackS.push(c);
        }
        for (char c : T.toCharArray()) {
            if (c == '#') {
                if (!stackT.isEmpty()) stackT.pop();
            }
            else stackT.push(c);
        }
        if (stackS.size() != stackT.size()) return false;
        while (!stackS.isEmpty()) {
            if (stackS.pop() != stackT.pop()) return false;
        }

        return true;
    }
}

