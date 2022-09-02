#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> stk{};
    int i = 0, j = 0, size = int(pushed.size());
    if (size <= 1) return true;

    while (i < size && j < size) {
      if (pushed[i] == popped[j]) {
        ++i, ++j;
        continue;
      }
      while (!stk.empty() && j < size && stk.top() == popped[j]) {
        stk.pop(), ++j;
      }
      stk.push(pushed[i]);
      ++i;
    }

    while (!stk.empty() && j < size && stk.top() == popped[j]) {
      stk.pop(), ++j;
    }

    return j == size;
  }

 private:

};

int main() {

  vector<int> x = {0, 1};
  vector<int> y = {1, 0};
  cout << Solution().validateStackSequences(x, y);

  return 0;
}
