#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maximumSwap(int num) {
    string charArray = to_string(num);
    int n = int(charArray.size());
    int maxIdx = n - 1, l = -1, r = -1;

    for (int i = n - 1; i >= 0; --i) {
      if (charArray[i] > charArray[maxIdx]) {
        maxIdx = i;
      } else if (charArray[i] < charArray[maxIdx]) {
        l = maxIdx;
        r = i;
      }
    }

    if (r >= 0) {
      swap(charArray[l], charArray[r]);
      return stoi(charArray);
    } else {
      return num;
    }
  }

 private:

};

int main() {

  return 0;
}
