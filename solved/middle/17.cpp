#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  string digitMap[8]{
      "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
  };

  void dfs_helper(vector<string> &res, const string &digits, string &cur, int idx, int n) {
    if (idx >= n) {
      res.push_back(cur);
      return;
    }

    for (const auto &item : digitMap[digits[idx] - '2']) {
      cur.push_back(item);
      dfs_helper(res, digits, cur, idx + 1, n);
      cur.pop_back();
    }
  }

 public:

  vector<string> letterCombinations(string digits) {
    int n = int(digits.size());
    if (n <= 0) return {};

    vector<string> res;
    string cur;
    dfs_helper(res, digits, cur, 0, n);
    return res;
  }

};

int main() {

  Solution().letterCombinations("23");

  return 0;
}
