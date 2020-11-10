import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=5143 lang=java
 *
 * [5143] 解压缩编码列表
 */

/* Test Case:

[]
[0,1]
[1,2]
[0,1,1,1,1,2,2,2]
[1,2,3,4]

*/

// @lc code=start
/* Method 1: Brute Force

    Time: O(n)
    Space: O(n)

class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> res = new ArrayList<>(16384);

        for (int i = 0, len = nums.length - 1, count = 0; i < len; i += 2) {
            count = nums[i];
            while (count > 0) {
                count--;
                res.add(nums[i + 1]);
            }
        }

        int[] arr = new int[res.size()];
        for (int i = 0; i < arr.length; ++i)
            arr[i] = res.get(i);
        return arr;
    }
}
*/

/* Method 2: Built-in method

    Time: O(n)
    Space: O(n)
*/
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int[] ans = new int[10000];
        int toIndex = 0;
        for (int i = 0, fromIndex = 0, len = nums.length; i < len; i += 2) {
            toIndex = fromIndex + nums[i];
            while (fromIndex < toIndex) {
                ans[fromIndex++] = nums[i + 1];
            }
        }

        return Arrays.copyOf(ans, toIndex);
    }
}
// @lc code=end

