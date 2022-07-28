#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:
  static const int start_year = 1950;

 public:

  int maximumPopulation(vector<vector<int>> &logs) {
    vector<int> arr(101);

    for (const auto &item : logs) { // build diff array
      arr[item[0] - start_year]++;
      arr[item[1] - start_year]--;
    }

    int res = 0, sum = 0, maxSum = 0;
    for (int i = 0; i < 101; ++i) {
      sum += arr[i];
      if (sum > maxSum) {
        sum = maxSum;
        res = i;
      }
    }

    return res + start_year;
  }

};

int main() {

  return 0;
}
