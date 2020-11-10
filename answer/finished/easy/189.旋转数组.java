import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=189 lang=java
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (38.44%)
 * Likes:    348
 * Dislikes: 0
 * Total Accepted:    61.8K
 * Total Submissions: 160.6K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-1,-100,3,99] 和 k = 2
 * 输出: [3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 说明:
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 要求使用空间复杂度为 O(1) 的 原地 算法。
 * 
 * 
 */

/* Test Case:

[1,2,3,4,5,6,7]
3
[-1,-100,3,99] 
2

*/

/* Method 1: New Array [Worst] 

    Time: O(n)
    Space: O(n) n = nums.length

class Solution {
    public void rotate(int[] nums, int k) {
        if (k < 0) {throw new RuntimeException("k >= 0!");}
        k = k % nums.length;
        if (k == 0) {return;}

        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length - k; ++i) {
            res[i + k] = nums[i];
        } 
        for (int i = nums.length - k; i < nums.length; ++i) {
            res[i + k - nums.length] = nums[i];
        }
        
        for (int i = 0; i < nums.length; ++i) {
            nums[i] = res[i];
        }
    }
}
*/

/* Method 2: In-place: Reverse [Best]!

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public void rotate(int[] nums, int k) {
        if (k < 0) {throw new RuntimeException("k >= 0!");}
        k = k % nums.length;
        if (k == 0) {return;}

        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
        
    }

    private void reverse(int[] nums, int start, int end) {
        int temp = 0;
        while (start < end) {
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
