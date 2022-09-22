#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    int n = int(arr.size()), m = int(pieces.size());
    vector<int> num_m(110);
    for (int i = 0; i < m; i++) num_m[pieces[i][0]] = i;
    for (int i = 0; i < n;) {
      auto &cur = pieces[num_m[arr[i]]];
      int len = int(cur.size()), idx = 0;
      while (idx < len && cur[idx] == arr[i + idx]) idx++;
      if (idx == len) i += len;
      else return false;
    }
    return true;
  }

 private:

};

int main() {

  return 0;
}
