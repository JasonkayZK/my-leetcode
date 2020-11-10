import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=274 lang=java
 *
 * [274] H指数
 */

/* Test Case:

[3,0,6,1,5]

*/

/* Method 1: Sort



*/
// @lc code=start
class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);

        int i = 0;
        while (i < citations.length && citations[citations.length - 1 - i] > i) i++;

        return i;
    }
}
// @lc code=end

