import java.util.Stack;

/*
 * @lc app=leetcode.cn id=234 lang=java
 *
 * [234] 回文链表
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
[1,2]
[1,2,2,1]
[1,3,1,1]
[-129,-129]

*/

/* Method 1: Stack 

    Time: O(n)
    Space: O(n)

class Solution {
    public boolean isPalindrome(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        ListNode n = head;
        while (n != null) {stack.push(n.val); n = n.next;}
        int len = stack.size();
        for (int i = 0; i < len / 2; ++i) {
            if (head.val != stack.pop()) {return false;}
            head = head.next;
        } 
        return true;
    }
}
*/

/* Method 2: Two Pointer: Fast-slow [Best]

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        ListNode slow = head, fast = head.next, pre = null, prepre = null;
        while (fast != null && fast.next != null) {
            // flip first half
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;

            pre.next = prepre;
            prepre = pre;
        }
        ListNode p2 = slow.next;
        slow.next = pre;
        // len(head) % 2 == 1  <==> fast == null
        ListNode p1 = fast == null ? slow.next : slow;
        while (p1 != null) {
            if (p1.val != p2.val) return false;
            p1 = p1.next;
            p2 = p2.next;
        }
        return true;
    }
}

