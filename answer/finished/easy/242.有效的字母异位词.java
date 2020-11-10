/*
 * @lc app=leetcode.cn id=242 lang=java
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (55.25%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    42.4K
 * Total Submissions: 76.8K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

/* Test Case:

""
""
"a"
""
""
"a"
"a"
"b"
"a"
"a"
"anagram"
"nagaram"
"rat"
"car"

*/

/* Method 1: Array as HashMap 

    Time: O(2 * n)
    Space: O(n)
*/

class Solution {
    public boolean isAnagram(String s, String t) {
        if ((s == null && t == null) || (s.length() == 0 && t.length() == 0)) return true;
        if ((s != null && t == null) || (s == null && t != null) || (s.length() != t.length())) return false;

        int[] dict = new int[26];
        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();

        for (char c : sArr) dict[c - 'a']++;
        for (char c: tArr) {
            dict[c - 'a']--;
            if (dict[c - 'a'] < 0) return false;
        }
        return true;
    }
}

