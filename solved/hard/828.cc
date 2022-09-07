#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int uniqueLetterString(string s) {
    int n = int(s.size());
    if (n <= 1) return n;

    unordered_map<char, vector<int>> c_map;
    for (int i = 0; i < n; ++i) {
      c_map[s[i]].emplace_back(i);
    }

    int res = 0;
    for (auto &&[_, arr] : c_map) {
      arr.insert(arr.begin(), -1);
      arr.emplace_back(n);
      for (int i = 1, a_size = int(arr.size()); i < a_size - 1; i++) {
        res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
