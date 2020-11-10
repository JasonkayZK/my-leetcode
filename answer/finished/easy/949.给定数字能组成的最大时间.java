import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=949 lang=java
 *
 * [949] 给定数字能组成的最大时间
 *
 * https://leetcode-cn.com/problems/largest-time-for-given-digits/description/
 *
 * algorithms
 * Easy (31.50%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    2K
 * Total Submissions: 6.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。
 * 
 * 最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。
 * 
 * 以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4]
 * 输出："23:41"
 * 
 * 
 * 示例 2：
 * 
 * 输入：[5,5,5,5]
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * A.length == 4
 * 0 <= A[i] <= 9
 * 
 * 
 */

/* Test Case:

[1,2,3,4]
[5,5,5,5]
[0,0,0,0]

*/

/* Method 1: Brute Force: Permutation

    Time: O(1)
    Space: O(1)

class Solution {

    private List<Integer> permutation;

    public String largestTimeFromDigits(int[] A) {
        int maxHour = -1, maxMin = -1;
        permutation = new ArrayList<>(25);
        permute(A, 0, 3);

        for (int n : permutation) {
            if (isValid(n / 100, n % 100)) {
                if ((n / 100 > maxHour) || (n / 100 == maxHour && n % 100 > maxMin)) {
                    maxHour = n / 100;
                    maxMin = n % 100;
                }
            }
        }
        return maxHour != -1 && maxMin != -1 ? String.format("%02d:%02d", maxHour, maxMin) : "";
    }  
    
    private void permute(int[] arr, int cur, int len) {
        if (cur == len) {
            permutation.add(arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3]);
        } else {
            for (int i = cur; i <= len; ++i) {
                swap(arr, cur, i);
                permute(arr, cur + 1, len);
                swap(arr, cur, i);
            }
        }
    }

    private void swap(int[] arr, int from, int to) {
        int temp = arr[from];
        arr[from] = arr[to];
        arr[to] = temp;
    }

    private boolean isValid(int hour, int min) {
        return hour <= 23 && min <= 59;
    }

}
*/

/* Method 1: Brute Force: Permutation [Better]

    Time: O(1)
    Space: O(1)
*/
class Solution {

    public String largestTimeFromDigits(int[] A) {
        int res = -1;
        for (int i = 0; i < 4; ++i) 
            for (int j = 0; j < 4; ++j)
                if (j != i) {
                    for (int k = 0; k < 4; ++k) 
                        if (k != i && k != j) {
                            int l = 6 - i - j - k;
                            int hours = 10 * A[i] + A[j], mins = 10 * A[k] + A[l];
                            if (hours < 24 && mins < 60) res = Math.max(res, hours * 60 + mins);
                        }
                }
        return res >= 0 ? String.format("%02d:%02d", res / 60, res % 60) : "";
    }  

}
