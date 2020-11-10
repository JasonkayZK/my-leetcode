/*
 * @lc app=leetcode.cn id=876 lang=java
 *
 * [876] 链表的中间结点
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/* Test Case:

[1]
[1,2]
[1,2,3,4,5]
[1,2,3,4,5,6]

*/

/* Method 1: Two-pointer: Fast-slow


    Time: O(n/2)
    Space: O(1)
*/
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode scott = new ListNode(0);
        scott.next = head;
        
        ListNode fast = scott, slow = scott;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return fast == null ? slow : slow.next;
    }
}

