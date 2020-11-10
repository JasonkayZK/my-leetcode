/*
 * @lc app=leetcode.cn id=21 lang=java
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (56.56%)
 * Likes:    580
 * Dislikes: 0
 * Total Accepted:    98.6K
 * Total Submissions: 174.3K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
[1,2,4]
[1,3,4]
[]
[1]
[1]
[]
[0]
[1,4,6]
[5]
[1,4,6]
[1,2]
[2,1]
[1,4,6]
[5]
[1,4,6]
[0]
*/

 /* Method 1: non-inplace [Not Best]
 
    Space complexity: O(m + n):  m = len(l1), n = len(l2)

    Time complexity: O(n): n = min(len(l1), len(l2))

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {return null;}
        if (l1 == null) {return l2;}
        if (l2 == null) {return l1;}

        // 哨兵结点
        ListNode scott = new ListNode(-1);
        ListNode cur = scott;

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                cur.next = new ListNode(l1.val);
                cur = cur.next;
                l1 = l1.next;
            } else {
                cur.next = new ListNode(l2.val);
                cur = cur.next;
                l2 = l2.next;
            }
        }
        while (l1 != null) {
            cur.next = new ListNode(l1.val);
            cur = cur.next;
            l1 = l1.next;    
        }  
        while (l2 != null) {
            cur.next = new ListNode(l2.val);
            cur = cur.next;
            l2 = l2.next;
        }

        return scott.next;
    }
}
*/

/* Method 2: In-place [Best]

    Space complexity: O(n): n = min(len(l1), len(l2))

    Time complexity: O(n): n = min(len(l1), len(l2))

*/

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {return l2;}
        if (l2 == null) {return l1;}

        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}

