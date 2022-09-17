#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string reverseLeftWords(string s, int n) {
    int size = int(s.size());
    n %= size;

    if (n == 0) return s;
    return string(s.substr(n, size)) + string(s.substr(0, n));
  }

 private:

};

int main() {

  return 0;
}
