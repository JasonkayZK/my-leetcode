#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<int> decode(vector<int> &encoded, int first) {
    int n = int(encoded.size());
    if (n <= 0) return {first};

    vector<int> res(n + 1, 0);
    res[0] = first;
    for (int i = 1; i < (n + 1); ++i) {
      res[i] = res[i - 1] ^ encoded[i - 1];
    }

    return res;
  }

};

int main() {

  return 0;
}
