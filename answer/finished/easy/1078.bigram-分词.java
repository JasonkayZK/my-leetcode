import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1078 lang=java
 *
 * [1078] Bigram 分词
 *
 * https://leetcode-cn.com/problems/occurrences-after-bigram/description/
 *
 * algorithms
 * Easy (59.59%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 4.1K
 * Testcase Example:  '"alice is a good girl she is a good student"\n"a"\n"good"'
 *
 * 给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中
 * second 紧随 first 出现，third 紧随 second 出现。
 * 
 * 对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：text = "alice is a good girl she is a good student", first = "a", second
 * = "good"
 * 输出：["girl","student"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：text = "we will we will rock you", first = "we", second = "will"
 * 输出：["we","rock"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 1000
 * text 由一些用空格分隔的单词组成，每个单词都由小写英文字母组成
 * 1 <= first.length, second.length <= 10
 * first 和 second 由小写英文字母组成
 * 
 * 
 */

/* Test Case: 

"alice is a good girl she is a good girl"
"a"
"good"
"alice is a good a good a good a good a good"
"a"
"good"
"we will we will rock you"
"we"
"will"

*/

/* Method 1: Regex: Replace 
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String pattern = first + " " + second;
        text = text.replaceAll(pattern, "&");

        String[] map = text.trim().split(" ");
        List<String> res = new ArrayList<>(map.length);
        for (int i = 0; i < map.length - 1; ++i) {
            if ("&".equals(map[i])) {
                if ("&".equals(map[i + 1])) res.add(first);
                else res.add(map[i + 1]);
            }
        }
        return res.toArray(new String[res.size()]);
    }
}
*/

/* Method 1: Straight Forward 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] map = text.trim().split(" ");
        List<String> res = new ArrayList<>(map.length);

        for (int i = 0; i < map.length - 2; ++i) {
            if (first.equals(map[i]) && second.equals(map[i + 1])) res.add(map[i + 2]);
        }
        return res.toArray(new String[res.size()]);
    }
}

