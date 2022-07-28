#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxConsecutive(int bottom, int top, vector<int> &special) {
    int n = int(special.size());
    if (n <= 0) return top - bottom + 1;

    sort(special.begin(), special.end());
    int res = special[0] - bottom;

    for (int i = 1; i < n; ++i) {
      res = max(res, special[i] - special[i - 1] - 1);
    }
    res = max(res, top - special[n - 1]);

    return res;
  }

 private:

};

int main() {

  vector<int> l = {35, 48};
  Solution().maxConsecutive(28, 50, l);

  return 0;
}
