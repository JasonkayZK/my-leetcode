/*
 * @lc app=leetcode.cn id=58 lang=java
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (30.76%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    37.9K
 * Total Submissions: 123.3K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

/* Test Case:

"Hello World"
"  J asfdasdf  "
""
"  asdfadsf  "
"asdfas"
"  asdf     asdfasdf"

*/

/* Method 1: 先处理字符串, 再从后向前找首个空格即可
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        if (s == null || s.length() == 0) {return 0;}

        char[] arr = s.toCharArray();
        for (int i = s.length() - 1; i >= 0; --i) {
            if (arr[i] == ' ') {
                return (s.length() - 1 - i);
            }
        }
        return s.length();
    }
}
*/

/* Method 1: [Shorter] */
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        return s.length() - 1 - s.lastIndexOf(" ");
    }
}

