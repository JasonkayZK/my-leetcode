#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:
  int zeta(long x) {
    int res = 0;
    while (x) {
      res += x / 5;
      x /= 5;
    }
    return res;
  }

  long long help(int k) {
    long long r = 5LL * k;
    long long l = 0;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (zeta(mid) < k) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return r + 1;
  }

  int preimageSizeFZF(int k) {
    return help(k + 1) - help(k);
  }
};

int main() {



  return 0;
}
