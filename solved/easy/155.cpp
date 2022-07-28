#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class MinStack {
 private:
  stack<int> x_stack;
  stack<int> min_stack;

 public:
  MinStack() {
    min_stack.push(INT_MAX);
  }

  void push(int x) {
    x_stack.push(x);
    min_stack.push(min(min_stack.top(), x));
  }

  void pop() {
    x_stack.pop();
    min_stack.pop();
  }

  int top() {
    return x_stack.top();
  }

  int getMin() {
    return min_stack.top();
  }
};

int main() {

  return 0;
}
