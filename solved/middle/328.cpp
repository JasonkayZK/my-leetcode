#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }

    ListNode *evenHead = head->next;
    ListNode *odd = head;
    ListNode *even = evenHead;
    while (even != nullptr && even->next != nullptr) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    odd->next = evenHead;
    return head;
  }

 private:

};

int main() {

  return 0;
}
