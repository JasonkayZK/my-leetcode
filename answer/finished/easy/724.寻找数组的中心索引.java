/*
 * @lc app=leetcode.cn id=724 lang=java
 *
 * [724] 寻找数组的中心索引
 */

/* Test Case:

[]
[1]
[1, 7, 3, 6, 5, 6]
[1, 2, 3]

*/

/* Method 1: Traverse two times

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int pivotIndex(int[] nums) {
        if (nums == null || nums.length == 0) return -1;
        if (nums.length == 1) return 0;

        int sum = 0;
        for (int n : nums) sum += n;

        int sumLeft = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (sumLeft * 2 + nums[i] == sum) return i;
            sumLeft += nums[i];
        }

        return -1;
    }
}

