#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> s;
    for (const auto &item : jewels) {
      s.emplace(item);
    }

    int res = 0;
    for (const auto &item : stones) {
      if (s.count(item) > 0) res++;
    }
    return res;
  }

};

int main() {
  int a = 666;
  vector<int> b({1, 2, 3});
  string c = "hello world";

  // after
  debug(a, b, c);  // a=666, b=[ 1, 2, 3, ], c=hello world

  return 0;
}
