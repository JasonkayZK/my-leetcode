/*
 * @lc app=leetcode.cn id=557 lang=java
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (67.27%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    25.8K
 * Total Submissions: 38.3K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */

/* Test Case:

" "
" 1"
"1 "
"  1  2 "
"  12   "
"Let's take LeetCode contest"

*/

/* Method 1: Counter

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        char[] str = s.toCharArray();
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            count++;
            if (str[i] == ' ') {
                reverseArr(str, i - count + 1, i - 1);
                count = 0;
            }

            if (i == s.length() - 1) {
                reverseArr(str, i - count + 1, i);
                count = 0;
            }
        }
        return new String(str);
    }

    private void reverseArr(char[] str, int start, int end) {
        char c = 0;
        while (start < end) {
            c = str[start];
            str[start] = str[end];
            str[end] = c;
            start++;
            end--;
        }
    }
}

