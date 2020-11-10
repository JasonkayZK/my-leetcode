/*
 * @lc app=leetcode.cn id=1071 lang=java
 *
 * [1071] 字符串的最大公因子
 */

/* Test Case:

"ABCABC"
"ABC"
"ABABAB"
"ABAB"
"LEET"
"CODE"

*/

/* Method 1: Recursive */
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length(), len2 = str2.length();
        int len = gcd(len1, len2);

        String res = str1.substring(0, len);
        if (isMatch(str1, res) && isMatch(str2, res)) return res;
        return "";
    }

    private Integer gcd(int n, int m) {
        return n == 0 ? m : gcd(m % n, n);
    }

    private Boolean isMatch(String str, String partten) {
        for (int i = 0; i < str.length(); ++i) {
            if (str.charAt(i) != partten.charAt(i % partten.length())) return false;
        }
        return true;
    }
}
