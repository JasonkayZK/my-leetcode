#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<string> removeAnagrams(vector<string> &words) {
    int n = int(words.size());
    if (n <= 1) return words;

    unordered_set<string> s;
    vector<string> res;
    for (int i = 0; i < n; ++i) {
      string temp = words[i];
      sort(temp.begin(), temp.end());

      if (s.count(temp) > 0) continue;
      else {
        s.emplace(temp);
        res.push_back(words[i]);
        if (i > 0) {
          string rem = words[i - 1];
          sort(rem.begin(), rem.end());
          s.erase(rem);
        }
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
