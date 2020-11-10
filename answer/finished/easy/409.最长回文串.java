import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=409 lang=java
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (49.66%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 17.2K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 *  
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */

/* Test Case:

""
"qwefqwfAasdgfPDOSAGJUPOQW"
"a"
"aa"
"aba"
"abbaa"
"abccccdd"

*/

/* Method 1: HashMap 

    Time: O(n)
    Space: O(1)

class Solution {
    public int longestPalindrome(String s) {
        if (s == null || s.length() == 0) return 0;
        
        Map<Character, Integer> map = new HashMap<>(s.length());
        char[] arr = s.toCharArray();
        for (char c : arr) 
            map.put(c, map.getOrDefault(c, 0) + 1);
        
        int len = 0;
        boolean isSingled = false;
        for (int v : map.values()) {
            if (v % 2 == 0) len += v;
            else {
                if (!isSingled) {
                    len += 1;
                    isSingled = true;
                }
                len += v - 1;
            }
        }
        return len;
    }
}
*/

/* Method 1: Set 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int longestPalindrome(String s) {
        if (s == null || s.length() == 0) return 0;
        
        Set<Character> set = new HashSet<>();
        int count = 0;
        char[] arr = s.toCharArray();
        for (char c : arr) {
            if (set.remove(c)) count++;
            else set.add(c);
        }

        return set.isEmpty() ? count * 2 : count * 2 + 1;
    }
}

