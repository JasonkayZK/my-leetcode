#include "../../utils/utils.h"
#include "../../data_structure/list.h"
#include "../../data_structure/tree.h"
#include "../../data_structure/trie.h"
#include "../../data_structure/segment_tree.h"
#include "../../data_structure/union_find.h"

class Solution {
 private:

  bool startsWith(const std::string &str, const std::string &prefix) {
    return (str.rfind(prefix, 0) == 0);
  }

 public:

  int countPrefixes(vector<string> &words, string s) {
    int res = 0;
    for (const auto &item : words) {
      if (startsWith(s, item)) res++;
    }
    return res;
  }

};

int main() {

  return 0;
}
