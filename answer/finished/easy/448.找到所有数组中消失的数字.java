import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=448 lang=java
 *
 * [448] 找到所有数组中消失的数字
 */

/* Test Case:

[4,3,2,7,8,2,3,1]
[1,2,3,4,5,6]
[3,4,2,1,3]

*/

/* Method 1: Sort by hand 

    Time: O(n)
    Space: O(1)

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();

        int cur = 0, len = nums.length, swapIndex, swap;
        while (cur < len) {
            while (nums[cur] != cur + 1 && nums[nums[cur] - 1] != nums[cur]) {
                swapIndex = nums[cur] - 1;
                swap = nums[cur];
                nums[cur] = nums[swapIndex];
                nums[swapIndex] = swap;
            }
            cur++;
        }

        for (int i = 0; i < len; ++i) {
            if (nums[i] - 1 != i) res.add(i + 1);
        }
        return res;
    }
}
*/

/* Method 2: Array Manipulation

    Time: O(n)
    Space: O(1)

*/
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < nums.length; ++i) {
            int val = Math.abs(nums[i]) - 1;
            if (nums[val] > 0) {
                nums[val] = -nums[val];
            }
        }
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] > 0) {
                res.add(i + 1);
            }
        }
        return res;
    }
}
