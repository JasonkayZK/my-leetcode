/*
 * @lc app=leetcode.cn id=896 lang=java
 *
 * [896] 单调数列
 *
 * https://leetcode-cn.com/problems/monotonic-array/description/
 *
 * algorithms
 * Easy (48.98%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 16.5K
 * Testcase Example:  '[1,2,2,3]'
 *
 * 如果数组是单调递增或单调递减的，那么它是单调的。
 * 
 * 如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A
 * 是单调递减的。
 * 
 * 当给定的数组 A 是单调数组时返回 true，否则返回 false。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,2,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：[6,5,4,4]
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1,3,2]
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 输入：[1,2,4,5]
 * 输出：true
 * 
 * 
 * 示例 5：
 * 
 * 输入：[1,1,1]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 50000
 * -100000 <= A[i] <= 100000
 * 
 * 
 */

/* Test Case: 

[1]
[1,2]
[2,1]
[1,1]
[1,2,2,3]
[6,5,4,4]
[1,3,2]
[1,2,4,5]
[1,1,1]
[11,11,9,4,3,3,3,1,-1,-1,3,3,3,5,5,5]

*/

/* Method 1: Math 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public boolean isMonotonic(int[] A) {
        int store = 0;
        for (int i = 0; i < A.length - 1; ++i) {
            int c = Integer.compare(A[i], A[i+1]);
            if (c != 0) {
                if (c != store && store != 0)
                    return false;
                store = c;
            }
        }

        return true;
    }
}

