#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  int trap(vector<int> &height) {
    int n = height.size();
    if (n <= 1) return 0;

    vector<int> l_max(n, 0), r_max(n, 0);
    int cur_max = -1;
    for (int i = 0; i < n; ++i) {
      cur_max = max(cur_max, height[i]);
      l_max[i] = cur_max;
    }
    cur_max = -1;
    for (int i = n - 1; i >= 0; --i) {
      cur_max = max(cur_max, height[i]);
      r_max[i] = cur_max;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += (min(l_max[i], r_max[i]) - height[i]);
    }
    return res;
  }

};

int main() {

  return 0;
}
