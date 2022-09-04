#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int numberOfWays(int startPos, int endPos, int k) {
    res = 0;
    unordered_map<int, int> memo;
    dfs_helper(startPos, endPos, k, memo);
    return res;
  }

 private:

  int dfs_helper(int curPos, const int endPos, int k, unordered_map<int, int> &memo) {
    int memo_key = get_memo_key(curPos, k);
    if (memo.count(memo_key) > 0) {
      if (memo[memo_key]) {
        res += memo[memo_key];
        res %= RES_NUM;
        return memo[memo_key];
      } else {
        return 0;
      }
    } else if (k == 0) {
      if ((curPos + k < endPos) || curPos - k < endPos) {
        return 0;
      }

      if (curPos == endPos) {
        ++res;
        res %= RES_NUM;
        return 1;
      }
      return 0;
    }

    int right_res = dfs_helper(curPos + 1, endPos, k - 1, memo);
    memo[get_memo_key(curPos + 1, k - 1)] = right_res;
    int left_res = dfs_helper(curPos - 1, endPos, k - 1, memo);
    memo[get_memo_key(curPos - 1, k - 1)] = left_res;

    return (left_res + right_res) % RES_NUM;
  }

  static int get_memo_key(int curPos, int k) {
    return k * 10000 + curPos;
  }

  int res;

  int RES_NUM = 1000000007;

};

int main() {

  return 0;
}
