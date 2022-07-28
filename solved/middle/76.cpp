#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<int> partitionLabels(string s) {
    int n = s.size();
    if (n <= 0) return {};

    int last[26];
    for (int i = 0; i < n; ++i) {
      last[s[i] - 'a'] = i;
    }

    vector<int> res;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      r = max(r, last[s[i] - 'a']);
      if (i == r) {
        res.push_back(r - l + 1);
        l = r + 1;
      }
    }
    return res;
  }
};

int main() {

  return 0;
}
