import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=784 lang=java
 *
 * [784] 字母大小写全排列
 */

/* Test Case:

"a1b2"
"3z4"
"12345"

*/

/* Method 1: Recursive */
class Solution {

    private List<String> res;

    public List<String> letterCasePermutation(String S) {
        res = new ArrayList<>();
        generateString(S, new StringBuilder(), 0);
        return res;
    }

    private void generateString(String s, StringBuilder sub, int index) {
        if (index == s.length()) {
            res.add(sub.toString());
            return;
        }
        while (index < s.length() && Character.isDigit(s.charAt(index))) {
            sub.append(s.charAt(index++));
        }
        if (index < s.length()) {
            generateString(s, new StringBuilder(sub).append(Character.toLowerCase(s.charAt(index))), index + 1);
            generateString(s, new StringBuilder(sub).append(Character.toUpperCase(s.charAt(index))), index + 1);
        } else {
            res.add(sub.toString());
        }
    }
}

