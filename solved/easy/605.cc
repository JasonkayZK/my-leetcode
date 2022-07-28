#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int len = int(flowerbed.size());

    int count = 0;
    for (int i = 0; i < len; i++) {
      if (flowerbed[i] == 0 && (i == len - 1 || flowerbed[i + 1] == 0) && (i == 0 || flowerbed[i - 1] == 0)) {
        flowerbed[i] = 1;
        count++;
      }
    }
    return count >= n;
  }

 private:

};

int main() {

  vector<int> l = {1, 0, 0, 0, 0, 0, 1};
  Solution().canPlaceFlowers(l, 2);

  return 0;
}
