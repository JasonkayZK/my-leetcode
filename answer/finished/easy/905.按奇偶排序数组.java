/*
 * @lc app=leetcode.cn id=905 lang=java
 *
 * [905] 按奇偶排序数组
 */

/* Test Case:

[1,2,1,1,1,1]
[1,1,1,1,1,2]
[1]
[2]
[1,1,1,1]
[2,2,2,2]
[3,1,2,4]

*/

/* Method 1: Two Pointer: In-place 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int[] sortArrayByParity(int[] A) {
        for (int l = 0, r = A.length - 1; l < r; l++, r--) {
            while (l < r && A[l] % 2 == 0) l++;
            while (l < r && A[r] % 2 != 0) r--;
            if (l < r) {
                int swap = A[l];
                A[l] = A[r];
                A[r] = swap;
            }
        }      
        return A;
    }
}

