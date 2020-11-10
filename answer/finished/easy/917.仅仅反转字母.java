/*
 * @lc app=leetcode.cn id=917 lang=java
 *
 * [917] 仅仅反转字母
 */

/* Test Case:

"ab-cd"
"----"
"---a----b-----c-----d----"
"a-bC-dEf-ghIj"
"Test1ng-Leet=code-Q!"

*/

/* Method 1: Two Pointer 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public String reverseOnlyLetters(String S) {
        char[] arr = S.toCharArray();
        for (int l = 0, r = arr.length - 1; l < r; l++, r--) {
            while (l < r && !Character.isLetter(arr[l])) l++;
            while (l < r && !Character.isLetter(arr[r])) r--;
            if (l < r) {
                char swap = arr[l];
                arr[l] = arr[r];
                arr[r] = swap;
            }
        }
        return new String(arr);
    }
}

