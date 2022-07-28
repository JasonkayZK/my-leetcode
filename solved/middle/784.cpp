#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  void helper(vector<string> &res, const string &s, string &cur, int idx, int n) {
    if (idx == n) {
      res.push_back(cur);
      return;
    }

    if (isalpha(s[idx]) == 0) { // not alpha
      cur.push_back(s[idx]);
      helper(res, s, cur, idx + 1, n);
      cur.pop_back();
    } else {
      cur.push_back(tolower(s[idx]));
      helper(res, s, cur, idx + 1, n);
      cur.pop_back();
      cur.push_back(toupper(s[idx]));
      helper(res, s, cur, idx + 1, n);
      cur.pop_back();
    }

  }

 public:

  vector<string> letterCasePermutation(string s) {
    vector<string> res;
    string cur;
    helper(res, s, cur, 0, int(s.size()));
    return res;
  }

};

int main() {

  Solution().letterCasePermutation("3z4");

  return 0;
}
