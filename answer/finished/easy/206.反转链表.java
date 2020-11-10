/*
 * @lc app=leetcode.cn id=206 lang=java
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (63.89%)
 * Likes:    543
 * Dislikes: 0
 * Total Accepted:    87.9K
 * Total Submissions: 137.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
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

[]
[1]
[1,1]
[1,2,3,4,5]

*/

/* Method 1: Iteration 
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode res = null, next = null;
        while (head != null) {
            next = head.next;
            head.next = res;
            res = head;
            head = next;
        }
        return res;
    }
}
*/

/* Method 2: Recursive */
class Solution {
    public ListNode reverseList(ListNode head) {
        return helper(head, null);
    }

    private ListNode helper(ListNode head, ListNode newHead) {
        if (head == null) return newHead;
        ListNode next = head.next;
        head.next = newHead;
        return helper(next, head);
    }
}

