import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */

/* Test Case:

[-1, 0, 1, 2, -1, -4]
[-5,-3,-1,1,5,3,2,1,5,6,7]

*/

/* Method 1: Two Pointer: Linear Search 

    Time: O(n^2)
    Extra Space: O(1)
*/
// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums == null || nums.length < 3) return res;
        Arrays.sort(nums);

        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue; // 去重
            
            int l = i + 1, r = nums.length - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    while (l < r && nums[l] == nums[l + 1]) l++; // 去重
                    while (l < r && nums[r] == nums[r - 1]) r--; // 去重
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
}
// @lc code=end