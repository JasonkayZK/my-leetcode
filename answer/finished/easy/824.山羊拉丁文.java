/*
 * @lc app=leetcode.cn id=824 lang=java
 *
 * [824] 山羊拉丁文
 */


/* Test Case:

"I"
"d"
"a"
"A"
"I I"
"I speak Goat Latin"

*/
/* Method 1: Brute force:


    Time: O(n)
*/
class Solution {
    public String toGoatLatin(String S) {
        String[] strs = S.split(" ");

        StringBuilder suffix = new StringBuilder("a");
        StringBuilder sb = new StringBuilder();

        for (String str : strs) {
            sb.append(solveStr(str, suffix));
            suffix.append("a");
        }

        return sb.substring(0, sb.length() - 1);
    }

    private StringBuilder solveStr(String s, StringBuilder suffix) {
        StringBuilder res = new StringBuilder();
        
        if (!isVowel(s)) {
            res.append(s.substring(1, s.length()));
            res.append(s.charAt(0));
        } else {
            res.append(s);
        }
        res.append("ma").append(suffix).append(" ");
        return res;
    }

    private boolean isVowel(String s) {
        char c = s.charAt(0);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
}

