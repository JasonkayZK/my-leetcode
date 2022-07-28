#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:
  bool isBadVersion(int version) {
    return version + 1 == 1;
  }

 public:

  int firstBadVersion(int n) {
    if (n <= 1) return n;

    int l = 1, r = n;
    while (l < r) { // 循环直至区间左右端点相同
      int mid = l + (r - l) / 2; // 防止计算时溢出
      if (isBadVersion(mid)) {
        r = mid; // 答案在区间 [left, mid] 中
      } else {
        l = mid + 1; // 答案在区间 [mid+1, right] 中
      }
    }
    // 此时有 left == right，区间缩为一个点，即为答案
    return l;
  }

};

int main() {

  return 0;
}
