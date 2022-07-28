#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> sortedArr{arr};
    sort(sortedArr.begin(), sortedArr.end());

    unordered_map<int, int> temp{};
    int cur = 1;
    for (int &i : sortedArr) {
      if (temp.count(i) > 0) {
        continue;
      } else {
        temp[i] = cur;
        ++cur;
      }
    }

    vector<int> ret(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
      ret[i] = temp[arr[i]];
    }
    return ret;
  }

 private:

};

int main() {

  return 0;
}
