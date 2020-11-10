import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=1089 lang=java
 *
 * [1089] 复写零
 *
 * https://leetcode-cn.com/problems/duplicate-zeros/description/
 *
 * algorithms
 * Easy (54.99%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 5.3K
 * Testcase Example:  '[1,0,2,3,0,4,5,0]'
 *
 * 给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
 * 
 * 注意：请不要在超过该数组长度的位置写入元素。
 * 
 * 要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,0,2,3,0,4,5,0]
 * 输出：null
 * 解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,2,3]
 * 输出：null
 * 解释：调用函数后，输入的数组将被修改为：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10000
 * 0 <= arr[i] <= 9
 * 
 * 
 */

/* Test Case:

[0]
[0,0,0,0]
[0,1,1,1]
[1,0,2,3,0,4,5,0]
[1]
[1,0]
[0,1]
[1,2,3]

*/

/* Method 1: Brute Force

    Time: O(n^2)
    Space: O(1)


class Solution {
    public void duplicateZeros(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] == 0) {
                for (int j = arr.length - 1; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                i++;
            }
        }

    }
}
*/

/* Method 2: Two Pointer: Fast-Slow

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public void duplicateZeros(int[] arr) {
        int fast = 0, slow = 0, len = arr.length;

        while (fast < len) {
            if (arr[slow] == 0) fast++;
            fast++;
            slow++;
        }
        slow--;
        fast--;
        
        while (slow >= 0) {
            if (fast < len) arr[fast] = arr[slow];
            if (arr[slow] == 0) arr[--fast] = arr[slow];             
            
            slow--;
            fast--;
        }
    }
}


