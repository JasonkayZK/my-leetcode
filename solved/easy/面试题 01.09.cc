#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool isFlipedString(string s1, string s2) {
    return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
  }

 private:

};

int main() {

  return 0;
}
