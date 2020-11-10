/*
 * @lc app=leetcode.cn id=125 lang=java
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (40.68%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    48K
 * Total Submissions: 118K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

/* Test Case:

""
"    "
"  , "
"1"
"  1   3    1 , "
"A man, a plan, a canal: Panama"
"race a car"

*/

/* Method 1: Two Pointer 

    Time Complexity: O(n) [Worst]
    Space Complexity: O(1)

class Solution {
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {return true;}

        char[] arr = s.toLowerCase().toCharArray();

        int head = 0, tail = arr.length - 1;
        while (head < tail) {
            while (head < tail && !isNumberOrChar(arr[tail])) tail--;
            while (head < tail && !isNumberOrChar(arr[head])) head++;
            if (head >= tail) {return true;}
            if (arr[head] != arr[tail]) return false;
            head++;
            tail--;
        }
        return true;
    }

    private boolean isNumberOrChar(char c) {
        return (c >= 97 && c <= 122) || (c >= 48 && c <= 57);
    }
}
*/

