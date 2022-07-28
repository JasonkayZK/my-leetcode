#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
    int n = int(queries.size());
    if (n <= 0) return {};

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      auto query = queries[i];
      int cur = 0;

      for (const auto &item : points) {
        long x = item[0] - query[0];
        long y = item[1] - query[1];
        if (x * x + y * y <= query[2] * query[2]) ++cur;
      }
      res[i] = cur;
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
