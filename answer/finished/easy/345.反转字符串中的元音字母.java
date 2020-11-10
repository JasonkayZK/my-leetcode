/*
 * @lc app=leetcode.cn id=345 lang=java
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (47.89%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 28.8K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

/* Test Case:

""
"a"
"ab"
"ba"
"aasdfqweg"
"eghpwehkpeowh"
"hello"
"holle"
"leetcode"
"leotcede"
"aA"

*/

/* Method 1: Two Pointer 

    Time: O(n / 2)
    Space: O(1)
*/
class Solution {
    public String reverseVowels(String s) {
        if (s == null || s.length() == 0) return s;

        char[] arr = s.toCharArray();
        int l = 0, r = arr.length - 1;
        char swap = 0;
        while (l < r) {
            while (l < r && !isVowel(arr[l])) l++;
            while (l < r && !isVowel(arr[r])) r--;
            if (l < r) {
                swap = arr[l];
                arr[l] = arr[r];
                arr[r] = swap;
                l++;
                r--;
            }
        }
        return new String(arr);
    }

    private boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' 
            || c == 'o' || c == 'u'
            ;
    }

}

