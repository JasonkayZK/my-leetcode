#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> sumZero(int n) {
    if (n <= 0) return {};

    int cnt = n / 2;
    vector<int> res;
    if ((n & 1) == 1) res.push_back(0);
    while (cnt > 0) {
      res.push_back(-cnt);
      res.push_back(cnt);
      --cnt;
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
