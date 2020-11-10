/*
 * @lc app=leetcode.cn id=941 lang=java
 *
 * [941] 有效的山脉数组
 */

/* Test Case:

[2,1]
[3,5,5]
[0,3,2,1]

*/

/* Method 1: Linear Search

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public boolean validMountainArray(int[] A) {
        if (A == null || A.length < 3) return false;

        int n = A.length, i = 0;
        while (i < n - 1 && A[i + 1] > A[i]) ++i;
        if (i == 0 || i == n - 1) return false;
        while (i < n - 1 && A[i + 1] < A[i]) ++i;

        return i == n - 1;
    }
}

