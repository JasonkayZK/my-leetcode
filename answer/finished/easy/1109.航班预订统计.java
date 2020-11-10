/*
 * @lc app=leetcode.cn id=1109 lang=java
 *
 * [1109] 航班预订统计
 *
 * https://leetcode-cn.com/problems/corporate-flight-bookings/description/
 *
 * algorithms
 * Easy (28.10%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    1.2K
 * Total Submissions: 4.2K
 * Testcase Example:  '[[1,2,10],[2,3,20],[2,5,25]]\n5'
 *
 * 这里有 n 个航班，它们分别从 1 到 n 进行编号。
 * 
 * 我们这儿有一份航班预订表，表中第 i 条预订记录 bookings[i] = [i, j, k] 意味着我们在从 i 到 j 的每个航班上预订了 k
 * 个座位。
 * 
 * 请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
 * 输出：[10,55,45,25,25]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= bookings.length <= 20000
 * 1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
 * 1 <= bookings[i][2] <= 10000
 * 
 * 
 */

/* Test Case:

[[1,2,10],[2,3,20],[2,5,25]]
5

*/

/* Method 1: Simultation 

    Time: O(n * m)
    Space: O(1)

class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] res = new int[n];
        for (int[] arr : bookings) addBooking(res, arr[0] - 1, arr[1] - 1, arr[2]);
        return res;
    }

    private void addBooking(int[] res, int start, int end, int val) {
        for (int i = start; i <= end; ++i) {
            res[i] += val;
        }
    }
}
*/

/* Method 2: Difference 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] res = new int[n];
        for (int[] arr : bookings) {
            res[arr[0] - 1] += arr[2];
            if (arr[1] < n) res[arr[1]] -= arr[2];
        }
        for (int i = 1; i < n; ++i) res[i] += res[i - 1];
        return res;
    }

}



