#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  double trimMean(vector<int> &arr) {
    int n = int(arr.size());
    sort(arr.begin(), arr.end());
    int partialSum = accumulate(arr.begin() + n / 20, arr.begin() + (19 * n / 20), 0);
    return partialSum / (n * 0.9);
  }

 private:

};

int main() {

  return 0;
}
