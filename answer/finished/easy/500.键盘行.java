import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/*
 * @lc app=leetcode.cn id=500 lang=java
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (66.97%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 13.8K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */


/* Test Case: 

[]
["dsqwz", "Qeqwrtwery"]
["Hello", "Alaska", "Dad", "Peace"]
["Hello", "Alaska", "Dad", "asdfqewtZ"]

*/

/* Method 1: Dict */
class Solution {

    private static final int[] dict = new int[] {
        2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 
        3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3
    };


    public String[] findWords(String[] words) {
        if (words == null || words.length == 0) return words;
        
        List<String> res = new ArrayList<>();
        for (String str : words) {
            if (isValid(str)) res.add(str);
        }
        return res.toArray(new String[res.size()]);
    }

    private boolean isValid(String str) {
        if (str == null || str.length() <= 1) return true;
        str = str.toLowerCase();
        int pattern = dict[str.charAt(0) - 'a'];
        for (int i = 0; i < str.length(); ++i)
            if (dict[str.charAt(i) - 'a'] != pattern) return false;

        return true;
    }
}

