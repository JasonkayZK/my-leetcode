#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<int> numberOfLines(vector<int> &widths, string s) {
    int n = int(s.size());
    if (n <= 0) return {0, 0};

    long long cnt = 0;
    for (const auto &item : s) {
      long long cur = widths[item - 'a'];
      if ((cnt + cur) % 100 != 0 && ((cnt + cur) / 100 > (cnt / 100))) { // next line
        cnt = ((cnt / 100) + 1) * 100 + cur;
      } else {
        cnt += cur;
      }
    }

    return {int(cnt / 100) + ((cnt % 100) != 0 ? 1 : 0), int(cnt % 100 == 0 ? 100 : cnt % 100)};
  }

};

int main() {

  vector<int> l = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                   10};
  Solution().numberOfLines(l, "abcdefghijklmnopqrstuvwxyz");

  return 0;
}
