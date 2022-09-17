#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string defangIPaddr(const string& address) {
    string res;
    for (const auto &item : address) {
      if (item == '.') {
        res += "[.]";
      } else {
        res.push_back(item);
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
