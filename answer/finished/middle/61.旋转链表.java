/*
 * @lc app=leetcode.cn id=61 lang=java
 *
 * [61] 旋转链表
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

[1,2,3,4,5]
2
[0,1,2]
4
[]
0

*/

/* Method 1: Math

    Time: > O(n)
    Space: O(1)
*/
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode scott = new ListNode(0);
        scott.next = head;

        int len = 0;
        ListNode cur = scott;
        while (cur.next != null) {
            len++;
            cur = cur.next;
        }
        if (len == 0) return scott.next;

        k %= len;
        k = len - k;
        if (k == len) return scott.next;

        int i = 0;
        ListNode newHeadpre = scott;
        while (i < k) {
            newHeadpre = newHeadpre.next;
            i++;
        }

        ListNode oldTail = newHeadpre;
        while (oldTail.next != null) oldTail = oldTail.next;

        oldTail.next = scott.next;
        scott.next = newHeadpre.next;
        newHeadpre.next = null;

        return scott.next;
    }
}
// @lc code=end

