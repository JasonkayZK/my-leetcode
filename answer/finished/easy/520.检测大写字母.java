/*
 * @lc app=leetcode.cn id=520 lang=java
 *
 * [520] 检测大写字母
 *
 * https://leetcode-cn.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (53.45%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 18.5K
 * Testcase Example:  '"USA"'
 *
 * 给定一个单词，你需要判断单词的大写使用是否正确。
 * 
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 * 
 * 
 * 全部字母都是大写，比如"USA"。
 * 单词中所有字母都不是大写，比如"leetcode"。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
 * 
 * 
 * 否则，我们定义这个单词没有正确使用大写字母。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "USA"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "FlaG"
 * 输出: False
 * 
 * 
 * 注意: 输入是由大写和小写拉丁字母组成的非空单词。
 * 
 */

/* Test Case:

"USA"
"FlaG"
"leetcode"
"Google"

*/

/* Method 1: Java API: String
class Solution {
    public boolean detectCapitalUse(String word) {
        if (word == null || word.length() == 0) return true;

        String upper = new String(word.toUpperCase());
        String lower = new String(word.toLowerCase());
        StringBuilder capital = new StringBuilder(word.toLowerCase());
        capital.setCharAt(0, Character.toUpperCase(word.charAt(0)));
        return word.equals(upper) || word.equals(lower) || word.equals(capital.toString());
    }
}
 */

/* Method 2: Traverse */
class Solution {
    public boolean detectCapitalUse(String word) {
        boolean first = false;
        int upper = 0, lower = 0;       
        for(int i = 0; i < word.length() ; i++) {
            if(Character.isUpperCase(word.charAt(i)) && i == 0) {
                first = true;
                upper++;
            }
            else if(Character.isUpperCase(word.charAt(i))) upper++;
            else lower++;
        }
        
        if(upper == word.length() || lower == word.length() || (first == true && lower == word.length() - 1)) return true;
        return false;
    }
}

