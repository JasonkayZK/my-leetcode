#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string removeDuplicateLetters(string s) {
    vector<int> cnt(26);
    for (const auto &item : s) {
      ++cnt[item - 'a'];
    }

    vector<bool> visited(26);
    string stk;
    for (const auto &item : s) {
      if (!visited[item - 'a']) {
        while (!stk.empty() && stk.back() > item) { // trim stk to current best
          if (cnt[stk.back() - 'a'] > 0) {
            visited[stk.back() - 'a'] = false;
            stk.pop_back();
          } else {
            break;
          }
        }
        visited[item - 'a'] = true;
        stk.push_back(item);
      }
      --cnt[item - 'a'];
    }

    return stk;
  }

 private:

};

int main() {

  return 0;
}
