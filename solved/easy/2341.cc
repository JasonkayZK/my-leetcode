#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> numberOfPairs(vector<int> &nums) {
    vector<int> res(2);
    int dict[101];
    fill(dict, dict + 101, 0);

    for (int num : nums) {
      dict[num]++;
    }

    for (int num : dict) {
      if (num != 0) {
        res[0] += num / 2;
        res[1] += num % 2;
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
