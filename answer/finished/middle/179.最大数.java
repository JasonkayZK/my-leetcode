import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=179 lang=java
 *
 * [179] 最大数
 */

/* Test Case:

[10,2]
[3,30,34,5,9]
[0, 0, 0]
[0,0]

*/

/* Method 1: Convert to String and Sort

    Time: > O(2n)
    Space: O(n)
*/
// @lc code=start
class Solution {

    private StringBuilder res;

    public String largestNumber(int[] nums) {
        res = new StringBuilder();
        Arrays.stream(nums).boxed().map(x -> x.toString()).sorted((x, y) -> (y + x).compareTo(x + y)).forEach(x -> res.append(x));
        return res.charAt(0) == '0' ? "0" : res.toString();
    }
}
// @lc code=end

