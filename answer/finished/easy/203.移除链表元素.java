/*
 * @lc app=leetcode.cn id=203 lang=java
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (42.17%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    35.2K
 * Total Submissions: 83.6K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
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

[1,2,6,3,4,5,6]
6
[]
1
[1]
1
[2]
1
[1,2]
1
[1,2]
2
[1,2]
3

*/

/* Method 1: Iteration: Scott 

    Time: O(n)
    Space: O(1)
*/

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode scott = new ListNode(0);
        scott.next = head;
        ListNode cur = scott;

        while (cur.next != null) {
            if (cur.next.val == val) cur.next = cur.next.next;
            else cur = cur.next;
        }
        return scott.next;
    }
}

