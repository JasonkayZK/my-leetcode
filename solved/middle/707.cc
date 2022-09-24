#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class MyLinkedList {
 public:
  MyLinkedList() {
    this->size = 0;
    this->head = new ListNode(0);
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    ListNode *cur = head;
    for (int i = 0; i <= index; i++) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    addAtIndex(0, val);
  }

  void addAtTail(int val) {
    addAtIndex(size, val);
  }

  void addAtIndex(int index, int val) {
    if (index > size) {
      return;
    }
    index = max(0, index);
    size++;
    ListNode *pred = head;
    for (int i = 0; i < index; i++) {
      pred = pred->next;
    }
    ListNode *toAdd = new ListNode(val);
    toAdd->next = pred->next;
    pred->next = toAdd;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      return;
    }
    size--;
    ListNode *pred = head;
    for (int i = 0; i < index; i++) {
      pred = pred->next;
    }
    ListNode *p = pred->next;
    pred->next = pred->next->next;
    delete p;
  }
 private:
  int size;
  ListNode *head;
};

int main() {



  return 0;
}
