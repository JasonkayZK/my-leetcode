#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int n = int(intervals.size());
    if (n <= 1) return 0;

    sort(intervals.begin(), intervals.end(), [](const auto &x, const auto &y) {
      return x[1] < y[1];
    });

    int res = 0, right = intervals[0][1];
    for (int i = 1; i < n; ++i) {
      if (intervals[i][0] < right) {
        res++;
      } else {
        right = intervals[i][1];
      }
    }
    return res;
  }

};

int main() {

  vector<vector<int>> l = {{-52, 31},
                           {-73, -26},
                           {82, 97},
                           {-65, -11},
                           {-62, -49},
                           {95, 99},
                           {58, 95},
                           {-31, 49},
                           {66, 98},
                           {-63, 2},
                           {30, 47},
                           {-40, -26}};

  Solution().eraseOverlapIntervals(l);

  return 0;
}
