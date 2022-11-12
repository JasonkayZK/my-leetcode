#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int numTilings(int n) {
    if (n == 1) return 1;
    long f[n + 1];
    f[0] = f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; ++i)
      f[i] = (f[i - 1] * 2 + f[i - 3]) % MOD;
    return f[n];
  }

 private:

  const int MOD = 1e9 + 7;

};

int main() {

  return 0;
}
