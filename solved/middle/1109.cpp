#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> res(n + 1);

    for (const auto &item : bookings) { // build diff array
      res[item[0] - 1] += item[2];
      res[item[1]] -= item[2];
    }

    // build sum array
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += res[i];
      res[i] = sum;
    }

    res.erase(res.end() - 1);
    return res;
  }

};

int main() {

  vector<vector<int>> l = {{1, 2, 10},
                           {2, 2, 15}};
  Solution().corpFlightBookings(l, 2);

  return 0;
}
