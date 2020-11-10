/*
 * @lc app=leetcode.cn id=680 lang=java
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (32.66%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 20.4K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */

/* Test Case:

"a"
"ab"
"aba"
"abca"
"abcdcda"
"abcdbba"
"abccda"
"dfaqwgqwg"
"fqwfwqvq"
"ebcbbececabbacecbbcbe"


*/

/* Method 1: Two Pointer

    Time: O(n/2)
    Space: O(1)
*/
class Solution {
    public boolean validPalindrome(String s) {
        if (s == null || s.length() <= 2) return true;

        char[] arr = s.toCharArray();
        for (int l = 0, r = s.length() - 1; l < r; ++l, --r) {
            if (arr[l] != arr[r]) 
                return (isPalindrome(arr, l + 1, r) || isPalindrome(arr, l, r - 1));
        }
        return true;
    }
        
    private boolean isPalindrome(char[] arr, int start, int end) {
        while (start < end) if (arr[start++] != arr[end--]) return false;
        return true;
    }
}

