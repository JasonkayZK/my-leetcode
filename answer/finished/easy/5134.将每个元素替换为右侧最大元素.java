/*
 * @lc app=leetcode.cn id=5134 lang=java
 *
 * [5134] 将每个元素替换为右侧最大元素
 */

/* Test Case:

[]
[1]
[1,2]
[2,1]
[5,4,3,2,1]
[17,18,5,4,6,1]

*/

// @lc code=start
/* Method 1: In-Place & Back-Traverse

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int[] replaceElements(int[] arr) {
        int max = -1, temp = -1;
        for (int cur = arr.length - 1; cur >= 0; --cur) {
            temp = arr[cur];
            arr[cur] = max;
            max = Math.max(temp, max);
        }
        return arr;
    }
}
// @lc code=end

