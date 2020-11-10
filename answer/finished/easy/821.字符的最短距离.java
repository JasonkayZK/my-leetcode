/*
 * @lc app=leetcode.cn id=821 lang=java
 *
 * [821] 字符的最短距离
 */

/* Test Case:

"loveleetcode"
'e'

*/

/* Method 1: Traverse: LtoR & RtoL

    Time: O(2n)
    Space: O(n)
*/
class Solution {
    public int[] shortestToChar(String S, char C) {
        int n = S.length();
        int[] res = new int[n];
        int prev = Integer.MIN_VALUE / 2;

        for (int i = 0; i < n; ++i) {
            if (S.charAt(i) == C) prev = i;
            res[i] = i - prev;
        }

        prev = Integer.MAX_VALUE / 2;
        for (int i = n - 1; i >= 0; --i) {
            if (S.charAt(i) == C) prev = i;
            res[i] = Math.min(prev - i, res[i]);
        }
        return res;
    }
}

