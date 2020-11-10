import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=167 lang=java
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (49.73%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    36.2K
 * Total Submissions: 72.8K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */

/* Test Case:

[1,2]
3
[2, 7, 11, 15]
9
[2, 7, 11, 15]
13
[2, 7, 11, 15]
17

*/

/* Method 1: Binary Search 

    Time: O(Nlog(N))
    Space: O(1)

class Solution {
    public int[] twoSum(int[] numbers, int target) {

        for (int i = 0; i < numbers.length; ++i) {
            int search = Arrays.binarySearch(numbers, i + 1, numbers.length, target - numbers[i]);
            if (search > 0) {
                return new int[] {i + 1, search + 1};
            }
        }

        throw new RuntimeException("Only one answer!");
    }

}
*/

/* Method 2: Two pointer 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int head = 0, tail = numbers.length - 1;
        while (numbers[head] + numbers[tail] != target) {
            if (numbers[head] + numbers[tail] > target) {tail--;}
            else {head++;}
        }
        return new int[] {head + 1, tail + 1};
    }

}


