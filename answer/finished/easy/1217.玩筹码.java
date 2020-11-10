/*
 * @lc app=leetcode.cn id=1217 lang=java
 *
 * [1217] 玩筹码
 */


/* Test Case:

[1]
[1,2,3]
[2,2,2,3,3]
[1,2,2,2,2]

*/

/* Method 1: Math

    Time: O(n)
    Space: O(1)
*/
 class Solution {
    public int minCostToMoveChips(int[] chips) {
        if (chips.length <= 1) return 0;
        int odd = 0, even = 0;
        for (int i = 0; i < chips.length; ++i) {
            if (chips[i] % 2 == 0) odd++;
            else even++;
        }
        return Math.min(odd, even);
    }
}

// @lc code=end

