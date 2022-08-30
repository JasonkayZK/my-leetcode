#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin(),
        left = right - 1,
        len = int(arr.size());
    while (k--) {
      if (left < 0) {
        ++right;
      } else if (right >= len) {
        --left;
      } else if (x - arr[left] <= arr[right] - x) {
        --left;
      } else {
        ++right;
      }
    }

    return {arr.begin() + left + 1, arr.begin() + right};
  }

 private:

};

int main() {

  return 0;
}
