/*
 * @lc app=leetcode.cn id=1290 lang=java
 *
 * [1290] 二进制链表转整数
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/* Test Case:

[1,0,1]
[0]
[1]
[1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
[0,0]

*/

/* Method 1: Brute Force 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int getDecimalValue(ListNode head) {
        int res = 0;
        while (head != null) {
            res = (res << 1) + head.val;
            head = head.next;
        }
        return res;
    }
}
// @lc code=end

