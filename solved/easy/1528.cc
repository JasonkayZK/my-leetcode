#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string restoreString(string s, vector<int> &indices) {
    int n = int(s.size());
    if (n <= 1) return s;

    for (int i = 0; i < n; ++i) {
      if (indices[i] != i) {
        char c = s[i];
        int idx = indices[i];

        while (idx != i) {
          swap(s[idx], c);
          swap(indices[idx], idx);
        }
        s[i] = c;
        indices[i] = i;
      }
    }
    return s;
  }

 private:

};

int main() {

  return 0;
}
