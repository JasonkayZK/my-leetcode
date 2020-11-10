import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=290 lang=java
 *
 * [290] 单词规律
 */

/* Test Case:

""
"a"
""
""
"a"
"cat"
"aa"
"cat cat"
"abba"
"dog cat cat dog"
"abba"
"dog cat cat fish"
"aaaa"
"dog cat cat dog"
"abba"
"dog dog dog dog"

*/

/* Method 1: One HashMap 

    Time: O(nlog(n))
    Space: O(n)

*/
class Solution {
    public boolean wordPattern(String pattern, String str) {
        if (pattern == null && str == null) return true;
        if (pattern == null || str == null) return false;

        char[] patternArr = pattern.toCharArray();
        String[] strArr = str.split(" ");
        if (patternArr.length != strArr.length) return false;
        int len = strArr.length;

        Map<Character, String> dict = new HashMap<>(len);
        
        for (int i = 0; i < len; ++i) {
            if (!dict.containsKey(patternArr[i])) {
                if (dict.containsValue(strArr[i])) return false;
                dict.put(patternArr[i], strArr[i]);
            } else {
                if (!dict.get(patternArr[i]).equals(strArr[i])) return false;
            }
        }
        return true;
    }
}

