#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
/* Method 1: Prev Pointer
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        if (head == nullptr) return head;

        ListNode* res = head;
        while (res->next != nullptr) {
            if (res->next->val == val) {
                res->next = res->next->next;
                continue;
            } else {
                res = res->next;
            }
        }
        return head;
    }
 */

/* Method 2: Recursive */
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
