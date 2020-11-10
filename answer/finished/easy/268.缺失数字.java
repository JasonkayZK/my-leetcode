import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=268 lang=java
 *
 * [268] 缺失数字
 */

/* Test Case:

[]
[3,0,1]
[9,6,4,2,3,5,7,0,1]
[0,1]
[0]
[1]

*/

/* Method 1: Sort 

    Time: O(n) = n * log(n)
    Space: O(1)

class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i) return i;
        }
        return nums.length;
    }
}
*/

/* Method 2: Bit Operation [XOR] 

    Time: O(n)
    Space: O(1)

class Solution {
    public int missingNumber(int[] nums) {
        int res = nums.length;
        for (int i = 0; i < nums.length; ++i) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
}
*/

/* Method 3: Sum 

    Time: O(n)
    Space: O(1)

class Solution {
    public int missingNumber(int[] nums) {
        int len = nums.length;
        int sum = (len + 0) * (len + 1) / 2;
        for (int i = 0; i < len; ++i) {
            sum -= nums[i];
        }
        return sum;
    }
}
*/

/* Method 4: Binary Search

    Time: O(n)
    Space: O(1)

*/
class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int left = 0, right = nums.length, mid = left + (right - left) / 2;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > mid) right = mid;
            else left = mid + 1;
        } 
        return left;
    }
}



