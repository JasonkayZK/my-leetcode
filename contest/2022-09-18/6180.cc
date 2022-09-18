#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int smallestEvenMultiple(int n) {
    return lcm(n, 2);
  }

 private:

  int gcd(int a, int b) {
    int da = max(a, b);
    int xiao = min(a, b);
    if (da % xiao == 0)
      return xiao;
    else
      return gcd(xiao, da % xiao);

  }

  // 两个整数的最小公倍数等于两整数之积除以最大公约数
  int lcm(int a, int b) {
    return a * b / gcd(a, b);
  }

};

int main() {

  return 0;
}
