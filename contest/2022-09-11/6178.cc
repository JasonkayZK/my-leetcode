#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minGroups(vector<vector<int>> &intervals) {
    int n = int(intervals.size());
    if (n <= 1) return n;

    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
      if (a[0] != b[0]) return a[0] < b[0];
      else return (a[1] - a[0]) < (b[1] - b[0]);
    });

    multiset<int, greater<>> val;
    for (const auto &item : intervals) {
      if (val.empty()) {
        val.emplace(item[1]);
        continue;
      }

      auto upper = val.upper_bound(item[0]);
      if (upper == val.end()) {
        val.emplace(item[1]);
      } else {
        val.erase(upper);
        val.emplace(item[1]);
      }
    }

    return int(val.size());
  }

 private:

};

int main() {

  // 4
//  vector<vector<int> > arr =
//      {{441459, 446342}, {801308, 840640}, {871890, 963447}, {228525, 336985}, {807945, 946787}, {479815, 507766},
//       {693292, 944029}, {751962, 821744}};

  vector<vector<int> > arr = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};

  std::cout << Solution().minGroups(arr);

  return 0;
}
