/*
 * @lc app=leetcode.cn id=328 lang=java
 *
 * [328] 奇偶链表
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



*/

/* Method 1: Two Pointer


*/
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) return head;

        ListNode first = head;
        ListNode second = head.next;
        ListNode secondHead = second;

        while (second != null && second.next != null) {
            first.next = second.next;
            first = first.next;
            second.next = first.next;
            second = second.next;
        }
        first.next = secondHead;
        return head;
    }
}
// @lc code=end

