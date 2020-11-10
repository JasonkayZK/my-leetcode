/*
 * @lc app=leetcode.cn id=922 lang=java
 *
 * [922] 按奇偶排序数组 II
 */

/* Test Case:

[1,2]
[2,1]
[4,2,5,7]

*/

/* Method 1: Two Pointer: In-place

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int[] sortArrayByParityII(int[] arr) {
        for (int doub = 0, single = 1; doub < arr.length && single < arr.length; doub += 2, single += 2) {
            while (doub < arr.length && arr[doub] % 2 == 0) doub += 2;
            while (single < arr.length && arr[single] % 2 != 0) single += 2;
            if (doub < arr.length && single < arr.length) {
                int swap = arr[doub];
                arr[doub] = arr[single];
                arr[single] = swap;
            }
        }
        return arr;
    }
}

