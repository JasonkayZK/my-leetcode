#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int countConsistentStrings(const string& allowed, vector<string> &words) {
    bool c_map[26];
    fill(c_map, c_map + 26, false);
    for (const auto &item : allowed) c_map[item - 'a'] = true;

    int res = 0;
    for (const auto &item : words) {
      int flag = true;
      for (const auto &x : item) {
        if (!c_map[x-'a']) {
          flag = false;
          break;
        }
      }
      if (flag) ++res;
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
