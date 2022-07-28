#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool threeConsecutiveOdds(vector<int> &arr) {
    int n = int(arr.size());
    if (n <= 2) return false;

    for (int i = 2; i < n; ++i) {
      if (is_odd(arr[i]) && is_odd(arr[i - 1]) && is_odd(arr[i - 2])) return true;
    }

    return false;
  }

 private:

  bool is_odd(int x) {
    return (x & 1) == 1;
  }

};

int main() {

  return 0;
}
