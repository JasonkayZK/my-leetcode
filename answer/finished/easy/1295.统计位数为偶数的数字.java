import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1295 lang=java
 *
 * [1295] 统计位数为偶数的数字
 */

/* Test Case:

[12,345,2,6,7896]
[2,3123,41234123,231]

*/

/* Method 1: Math + Lambda

    Time: O(n)
    Space: O(1)
*/
// @lc code=start
class Solution {

    public int findNumbers(int[] nums) {
        return (int)Arrays.stream(nums).filter(x -> (int)(Math.log10(x) + 1) % 2 == 0).count();
    }

}
// @lc code=end

