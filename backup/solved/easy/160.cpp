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

  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 private:

/* Two Pointer */
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *curA = headA;
    ListNode *curB = headB;

    while (curA != nullptr || curB != nullptr) {
      if (curA == curB) return curA;
      curA = !curA ? headB : curA->next;
      curB = !curB ? headA : curB->next;
    }

    return nullptr;
  }
};
