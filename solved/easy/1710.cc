#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maximumUnits(vector<vector<int>> &&boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](const vector<int> &x, const vector<int> &y) {
           return x[1] > y[1];
         });

    int res = 0, curBoxes = 0;
    for (const auto &item : boxTypes) {
      if (curBoxes + item[0] <= truckSize) {
        res += item[0] * item[1];
        curBoxes += item[0];
      } else {
        res += (truckSize - curBoxes) * item[1];
        break;
      }
    }
    return res;
  }

 private:

};

int main() {

  Solution().maximumUnits({{1, 3}, {2, 2}, {3, 1}}, 4);

  return 0;
}
