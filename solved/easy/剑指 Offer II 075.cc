#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> dict;
    int m = int(arr2.size());
    for (int i = 0; i < m; ++i) dict[arr2[i]] = i;
    sort(arr1.begin(), arr1.end(), [&dict](int x, int y) {
      auto exist_x = dict.count(x), exist_y = dict.count(y);
      if (exist_x <= 0 && exist_y <= 0) {
        return x < y;
      } else if (exist_x > 0 && exist_y > 0) {
        return dict[x] < dict[y];
      } else {
        return exist_x > exist_y;
      }

    });
    return arr1;
  }

 private:

};

int main() {

  return 0;
}
