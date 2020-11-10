import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=1309 lang=java
 *
 * [1309] 解码字母到整数映射
 */

/* Test Case:

""
"1"
"10#11#12"
"1326#"
"25#"
"12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"

*/

// @lc code=start

/* Method 1: From tail:

    Time: O(n)
    Space: O(1)
*/
class Solution {

    private static Map<String, Character> dict;

    static {
        dict = new HashMap<>();
        dict.put("1", 'a');
        dict.put("2", 'b');
        dict.put("3", 'c');
        dict.put("4", 'd');
        dict.put("5", 'e');
        dict.put("6", 'f');
        dict.put("7", 'g');
        dict.put("8", 'h');
        dict.put("9", 'i');
        dict.put("10", 'j');
        dict.put("11", 'k');
        dict.put("12", 'l');
        dict.put("13", 'm');
        dict.put("14", 'n');
        dict.put("15", 'o');
        dict.put("16", 'p');
        dict.put("17", 'q');
        dict.put("18", 'r');
        dict.put("19", 's');
        dict.put("20", 't');
        dict.put("21", 'u');
        dict.put("22", 'v');
        dict.put("23", 'w');
        dict.put("24", 'x');
        dict.put("25", 'y');
        dict.put("26", 'z');
    }

    public String freqAlphabets(String s) {
        StringBuilder sb = new StringBuilder();

        for (int i = s.length() - 1; i >= 0;) {
            if ('#' == s.charAt(i)) {
                sb.append(dict.get(s.substring(i - 2, i)));
                i -= 3;
            } else {
                sb.append(dict.get(s.substring(i, i + 1)));
                i--;
            }
            
        }
        
        return sb.reverse().toString();
    }

}
// @lc code=end

