#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:
  bool isVowels(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:

  string removeVowels(string s) {
    int n = int(s.size());
    if (n <= 1) return s;

    string res{};
    for (const auto &item : s) {
      if (!isVowels(item)) {
        res.push_back(item);
      }
    }
    return res;
  }

};

int main() {

  return 0;
}
