#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int scoreOfParentheses(const string &s) {
    int res = 0, n = int(s.size());
    while (idx < n && s[idx] == '(') {
      ++idx;
      if (s[idx] == ')') res += 1;
      else res += scoreOfParentheses(s) * 2;
      ++idx;
    }
    return res;
  }

 private:

  int idx;
};

int main() {

  return 0;
}
