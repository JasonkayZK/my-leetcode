import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=383 lang=java
 *
 * [383] 赎金信
 */

/* Test Case:

"a"
"b"
"aa"
"ab"
"aa"
"aab"

*/

/* Method 1: Char dict 

    Time: O(m + n): m = len(ransomNote), n = len(magazine)
    Space: O(1)

*/

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] magDict = new int[26];
        char[] magArr = magazine.toCharArray();
        char[] ransomArr = ransomNote.toCharArray();

        for (int i = 0; i < magArr.length; ++i) {
            magDict[magArr[i] - 'a']++;
        }

        for (int i = 0; i < ransomArr.length; ++i) {
            magDict[ransomArr[i] - 'a']--;
            if (magDict[ransomArr[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
}

