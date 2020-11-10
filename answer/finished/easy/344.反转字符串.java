/*
 * @lc app=leetcode.cn id=344 lang=java
 *
 * [344] 反转字符串
 */

/* Test Case:

[]
["a"]
["a","b"]
["h","e","l","l","o"]
["h","e","l","l","o"]

*/

/* Method 1: Two Pointer

    Time: O(n / 2)
    Space: O(1)
*/
class Solution {
    public void reverseString(char[] s) {
        if (s == null || s.length <= 1) {return;}
        int l = 0, r = s.length - 1;
        char swap = 0;
        while (l < r) {
            swap = s[l];
            s[l] = s[r];
            s[r] = swap;
            l++;
            r--;
        }
    }
}

