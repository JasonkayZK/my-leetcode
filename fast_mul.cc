#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quick_mul(x, N) : 1.0 / quick_mul(x, -N);
  }

 private:

  double quick_mul(double x, long long n) {
    if (n == 0) return 1.0;

    double y = quick_mul(x, n >> 1);
    return (n & 1) == 0 ? y * y : y * y * x;
  }

};

int main() {

  return 0;
}
