#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

  static const int mod = 1000000007;

 public:

  int waysToStep(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    long long x = 1, y = 2, z = 4;
    for (int i = 4; i <= n; ++i) {
      long long temp = (x + y + z) % mod;
      x = y;
      y = z;
      z = temp;
    }

    return int(z);
  }

};

int main() {

  return 0;
}
