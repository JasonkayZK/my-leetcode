/*
 * @lc app=leetcode.cn id=88 lang=java
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (45.03%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    62.2K
 * Total Submissions: 138.1K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

/* Test Case:

[1,2,3,0,0,0]
3
[2,5,6]
3
[1,0,0,0]
1
[-2,-1]
2

*/

/* Method 1: Two Pointer */
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int cur1 = m - 1, cur2 = n - 1;
        int tail = m + n - 1;
        while (cur1 >= 0 && cur2 >= 0) {
            if (nums1[cur1] > nums2[cur2]) {
                nums1[tail--] = nums1[cur1--];
            } else {
                nums1[tail--] = nums2[cur2--];
            }
        }
        while (cur1 >= 0) {nums1[tail--] = nums1[cur1--];}
        while (cur2 >= 0) {nums1[tail--] = nums2[cur2--];}

    }
}

