/*
 * @lc app=leetcode.cn id=859 lang=java
 *
 * [859] 亲密字符串
 */

/* Test Case:

"ab"
"ba"
"ab"
"ab"
"aa"
"aa"
"aaaaaaabc"
"aaaaaaacb"
""
"aa"
"abcd"
"badc"

*/

/* Method 1:

    Time: O(n)
    Space: O(1)
*/
// @lc code=start
class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;
        char[] arrA = A.toCharArray();
        char[] arrB = B.toCharArray();
        int[] dict = new int[26];

        int diffCount = 0;
        int[] diff = new int[3];
        boolean hasIdentical = false;
        for (int i = 0; i < arrA.length; ++i) {
            if (arrA[i] != arrB[i]) diff[diffCount++] = i;
            if (diffCount > 2) return false;
            if (!hasIdentical) {
                dict[arrA[i] - 'a']++;
                if (dict[arrA[i] - 'a'] >= 2) hasIdentical = true;
            }
        }
        return (diffCount == 0 && hasIdentical) || (diffCount == 2 && arrA[diff[0]] == arrB[diff[1]] && diffCount == 2 && arrA[diff[1]] == arrB[diff[0]]);
    }
}
// @lc code=end

