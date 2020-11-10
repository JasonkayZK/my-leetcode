import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=561 lang=java
 *
 * [561] 数组拆分 I
 */

/* Test Case:

[1,4,3,2]

*/

/* Method 1: 

    Time: O(nlog(n))
    Space: O(1)

class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);

        int res = 0;
        for (int i = 0; i < nums.length; i += 2) {
            res += nums[i];
        }
        return res;
    }
}
*/

/* Method 2: HashMap

    Time: O(n)
    Space: O(n)
*/
public class Solution {
    public int arrayPairSum(int[] nums) {
        int[] arr = new int[20001];
        int lim = 10000;
        for (int num: nums) arr[num + lim]++;
        int d = 0, sum = 0;
        for (int i = -10000; i <= 10000; i++) {
            sum += (arr[i + lim] + 1 - d) / 2 * i;
            d = (2 + arr[i + lim] - d) % 2;
        }
        return sum;
    }
} 
