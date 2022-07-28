#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool detectCapitalUse(string word) {
    if (islower(word[0])) {
      return std::count_if(word.begin(), word.end(),
                           [](char c) { return isupper(c); }) == 0;
    }
    int n = word.size();
    return std::count_if(std::next(word.begin()), word.end(),
                         [](char c) { return isupper(c); }) == n - 1 ||
        std::count_if(std::next(word.begin()), word.end(),
                      [](char c) { return islower(c); }) == n - 1;
  }

 private:

};

int main() {

  return 0;
}
