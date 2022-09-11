#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minOperations(vector<string> &logs) {
    stack<bool> stk;

    for (const auto &item : logs) {
      if (item == "../") {
        if (!stk.empty())stk.pop();
      } else if (item == "./") continue;
      else stk.push(true);
    }
    return stk.size();
  }

 private:

};

int main() {

  Solution().minOperations({"./", "../", "./"});

  return 0;
}
