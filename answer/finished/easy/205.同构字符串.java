import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=205 lang=java
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (45.69%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 34.2K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */

/* Test Case:

""
""
""
"a"
"a"
""
"egg"
"aaa"
"aaa"
"egg"
"egg"
"add"
"foo"
"bar"
"paper"
"title"

*/

/* Method 1: HashMap

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if ((s == null && t == null) || (s.length() == 0 && t.length() == 0)) return true;
        if (s == null || t == null || s.length() != t.length()) return false;

        Map<Character, Character> map = new HashMap<>(s.length());
        for (int i = 0; i < s.length(); ++i) {
            if (!map.containsKey(s.charAt(i))) {
                if (map.containsValue(t.charAt(i))) {
                    return false;
                }
                map.put(s.charAt(i), t.charAt(i));
            } else {
                if (map.get(s.charAt(i)) != t.charAt(i)) return false;
            }
        }

        return true;
    }
}


