/*
 * @lc app=leetcode.cn id=925 lang=java
 *
 * [925] 长按键入
 *
 * https://leetcode-cn.com/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (42.86%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 9.2K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
 * 
 * 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：name = "alex", typed = "aaleex"
 * 输出：true
 * 解释：'alex' 中的 'a' 和 'e' 被长按。
 * 
 * 
 * 示例 2：
 * 
 * 输入：name = "saeed", typed = "ssaaedd"
 * 输出：false
 * 解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
 * 
 * 
 * 示例 3：
 * 
 * 输入：name = "leelee", typed = "lleeelee"
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：name = "laiden", typed = "laiden"
 * 输出：true
 * 解释：长按名字中的字符并不是必要的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * name.length <= 1000
 * typed.length <= 1000
 * name 和 typed 的字符都是小写字母。
 * 
 * 
 * 
 * 
 * 
 * 
 */

/* Test Case:



*/

/* Method 1: Two Pointer 

    Time: O(min(m,n))
    Space: O(1)
*/
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int cur = 0;
        for (char c : name.toCharArray()) {
            if (cur == typed.length()) return false;
            if (typed.charAt(cur) != c) {
                if (cur == 0 || typed.charAt(cur - 1) != typed.charAt(cur)) return false;
                char temp = typed.charAt(cur);
                while (cur < typed.length() && typed.charAt(cur) == temp) cur++;
                if (cur == typed.length() || typed.charAt(cur) != c) return false;
            }
            cur++;
        }
        return true;
    }
}
