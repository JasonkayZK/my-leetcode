import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=852 lang=java
 *
 * [852] 山脉数组的峰顶索引
 */

/* Method 1: Linear Search 

    Time: O(n)
    Space: O(1)

class Solution {
    public int peakIndexInMountainArray(int[] A) {
        for (int i = 1; i < A.length - 1; ++i) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) return i;
        }
        throw new RuntimeException("No result!");
    }
}
*/

/* Method 1: Binary Search 

    Time: O(log(n))
    Space: O(1)
*/
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int low = 0, high = arr.length - 1, mid = 0;

        while(low < high) {
            mid = (high - low) / 2 + low;
            if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) low = mid + 1;
            else if (arr[mid + 1] < arr[mid] && arr[mid] < arr[mid - 1]) high = mid - 1;
            else return mid;
        }
        return low;
    }
}

