#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> arr(1001);

    for (const auto &item : trips) { // build diff array
      arr[item[1]] += item[0];
      arr[item[2]] -= item[0];
    }

    int sum = 0;
    for (const auto &item : arr) {
      sum += item;
      if (sum > capacity) return false;
    }

    return true;
  }

};

int main() {

  return 0;
}
