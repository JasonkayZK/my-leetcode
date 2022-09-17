#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int countPoints(string rings) {
    int n = rings.size();
    vector<int> status(10);   // 状态数组
    // 遍历颜色位置对维护状态数组
    for (int i = 0; i < n; i += 2) {
      int idx = rings[i + 1] - '0';
      if (rings[i] == 'R') {
        status[idx] |= 1;
      } else if (rings[i] == 'G') {
        status[idx] |= 2;
      } else {
        status[idx] |= 4;
      }
    }
    // 统计集齐三色环的杆的数量
    int res = 0;
    for (int i = 0; i < 10; ++i) {
      if (status[i] == 7) {
        ++res;
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
