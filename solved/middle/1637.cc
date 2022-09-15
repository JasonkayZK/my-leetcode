#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxWidthOfVerticalArea(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a[0] < b[0];
         }
    );

    int res = 0, n = int(points.size());
    for (int i = 1; i < n; ++i) {
      if (points[i][0] - points[i - 1][0] == 0) continue;
      res = max(res, points[i][0] - points[i - 1][0]);
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
