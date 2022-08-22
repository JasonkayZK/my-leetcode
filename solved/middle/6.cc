#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:
  string convert(string s, int numRows) {
    int n = s.length(), r = numRows;
    if (r == 1 || r >= n) {
      return s;
    }
    string ans;
    int t = r * 2 - 2;
    for (int i = 0; i < r; ++i) { // 枚举矩阵的行
      for (int j = 0; j + i < n; j += t) { // 枚举每个周期的起始下标
        ans += s[j + i]; // 当前周期的第一个字符
        if (0 < i && i < r - 1 && j + t - i < n) {
          ans += s[j + t - i]; // 当前周期的第二个字符
        }
      }
    }
    return ans;
  }
};

int main() {

  return 0;
}
