#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class MyCircularDeque {
 public:

  explicit MyCircularDeque(int k) {
    capacity = k + 1;
    head = tail = 0;
    elements = vector<int>(k + 1);
  }

  bool insertFront(int value) {
    if (isFull()) return false;
    head = (head - 1 + capacity) % capacity;
    elements[head] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) return false;
    elements[tail] = value;
    tail = (tail + 1) % capacity;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) return false;
    head = (head + 1) % capacity;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) return false;
    tail = (tail - 1 + capacity) % capacity;
    return true;
  }

  int getFront() {
    if (isEmpty()) return -1;
    return elements[head];
  }

  int getRear() {
    if (isEmpty()) return -1;
    return elements[(tail - 1 + capacity) % capacity];
  }

  bool isEmpty() {
    return head == tail;
  }

  bool isFull() {
    return (tail + 1) % capacity == head;
  }

 private:
  vector<int> elements;
  int head, tail;
  int capacity;
};
