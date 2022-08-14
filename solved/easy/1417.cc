#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string reformat(string s) {
    if (s.size() <= 1) return s;

    int letterCur = 0, numCur = 0, len = int(s.size());
    for (int i = 0; i < len; ++i) {
      if (isdigit(s[i])) ++numCur;
      else ++letterCur;
    }
    if (abs(letterCur - numCur) > 1) return "";

    bool numTurns = numCur > letterCur;
    letterCur = 0, numCur = 0;
    string res{};
    while (numCur < len || letterCur < len) {
      if (numTurns) {
        while (numCur < len && isdigit(s[numCur]) == 0) ++numCur;
        if (numCur < len) {
          res.push_back(s[numCur]);
          ++numCur;
        }
      } else {
        while (letterCur < len && isalpha(s[letterCur]) == 0) ++letterCur;
        if (letterCur < len) {
          res.push_back(s[letterCur]);
          ++letterCur;
        }
      }
      numTurns = !numTurns;
    }

    return res;
  }

 private:

};

int main() {

  Solution().reformat("a0b1c2");

  return 0;
}
