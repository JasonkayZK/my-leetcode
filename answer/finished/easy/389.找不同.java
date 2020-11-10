/*
 * @lc app=leetcode.cn id=389 lang=java
 *
 * [389] 找不同
 */

/* Test Case:

"abcd"
"abcde"

*/

/* Method 1: Char array Hashmap 

    Time: O(2m + 1)
    Space: O(m + 1), m = len(s)
*/

class Solution {
    public char findTheDifference(String s, String t) {
        int[] arr = new int[26];

        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();

        for (char c : sArr) arr[c - 'a']++;
        for (char c : tArr) {
            arr[c - 'a']--;
            if (arr[c - 'a'] == -1) return c;
        }

        throw new RuntimeException("No result!");
    }
}

