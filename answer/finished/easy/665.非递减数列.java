/*
 * @lc app=leetcode.cn id=665 lang=java
 *
 * [665] 非递减数列
 */

/* Test Case:

[4,2,3]
[4,2,1]

*/

/* Method 1: Math

    Time: O(1)
    Space: O(1)
*/
// @lc code=start
class Solution {
    public boolean checkPossibility(int[] nums) {
        int cnt = 0;
        for(int i = 0; i < nums.length - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                int tmp = nums[i];
                if(i >= 1) {
                    nums[i] = nums[i - 1];
                } else {
                    nums[i] = nums[i + 1];
                }
                if(nums[i] > nums[i + 1]) {
                    nums[i] = tmp;
                    nums[i + 1] = nums[i];
                }
                cnt++;
                if(cnt == 2) {
                    return false;
                }
            }
        }
        return true;
    }
}
// @lc code=end

