/*
 * @lc app=leetcode.cn id=83 lang=java
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (47.22%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    39.4K
 * Total Submissions: 83.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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

[1,1,2]
[]
[1]
[1,2,2,2,3]
[1,3]
[1,2,2,2,2,3,2]

*/

/* Method 1: In-place: Merge 
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {return head;}
        
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            if (cur.next.val == cur.val) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }

        return head;
    }
}
*/

/* Method 2: Recursive [Best] */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {return head;}
        
        head.next = deleteDuplicates(head.next);
        return head.val == head.next.val ? head.next : head;
    }
}

