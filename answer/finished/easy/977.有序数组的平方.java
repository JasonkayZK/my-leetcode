/*
 * @lc app=leetcode.cn id=977 lang=java
 *
 * [977] 有序数组的平方
 */

/* Test Case:

[-3,-2,-1]
[1,2,3]
[-4,-1,0,3,10]
[-7,-3,2,3,11]

*/

/* Method 1: Two Pointer 

    Time: O(n)
    Space: O(n)
*/
class Solution {
    public int[] sortedSquares(int[] arr) {
        int[] res = new int[arr.length];
        int index = res.length - 1;
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            if (arr[l] * arr[l] > arr[r] * arr[r]) {
                res[index--] = arr[l] * arr[l];
                l++;
            } else {
                res[index--] = arr[r] * arr[r];
                r--;
            }
        }
        return res;
    }
}

