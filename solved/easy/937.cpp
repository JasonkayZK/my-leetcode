#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 private:

 public:

  vector<string> reorderLogFiles(vector<string> &logs) {
    stable_sort(logs.begin(), logs.end(),
                [](const string &x, const string &y) -> bool {
                  int pos1 = x.find_first_of(' ');
                  int pos2 = y.find_first_of(' ');
                  bool isDigit1 = isdigit(x[pos1 + 1]);
                  bool isDigit2 = isdigit(y[pos2 + 1]);
                  if (isDigit1 && isDigit2) {
                    return false;
                  }
                  if (!isDigit1 && !isDigit2) {
                    string s1 = x.substr(pos1);
                    string s2 = y.substr(pos2);
                    if (s1 != s2) {
                      return s1 < s2;
                    }
                    return x < y;
                  }
                  return !isDigit1;
                });
    return logs;
  }

};

int main() {

  return 0;
}
