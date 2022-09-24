#include "../../utils/utils.h"
#include "../../data_structure/list.h"
#include "../../data_structure/tree.h"
#include "../../data_structure/trie.h"
#include "../../data_structure/segment_tree.h"
#include "../../data_structure/union_find.h"

class Solution {
 public:

  int temperatureTrend(vector<int> &temperatureA, vector<int> &temperatureB) {
    int m = int(temperatureA.size());
    int cur = 0, res = 0;
    for (int i = 0; i < m - 1; ++i) {
      int cur_a = temperatureA[i + 1] - temperatureA[i],
          cur_b = temperatureB[i + 1] - temperatureB[i];

      if ((cur_a == 0 && cur_b == 0) || (cur_a * cur_b > 0)) ++cur;
      else cur = 0;
      res = max(res, cur);
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
