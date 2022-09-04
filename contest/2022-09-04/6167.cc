#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool checkDistances(string s, vector<int> &distance) {
    unordered_map<char, int> c_map;
    vector<int> retDistance(26);
    for (int i = 0; i < s.size(); ++i) {
      if (c_map.count(s[i]) > 0) {
        retDistance[s[i] - 'a'] = i - c_map[s[i]] - 1;
      } else {
        c_map.emplace(make_pair(s[i], i));
      }
    }

    for (int i = 0; i < retDistance.size(); ++i) {
      if (c_map.count(i + 'a') <= 0) continue;
      if (retDistance[i] != distance[i]) return false;
    }
    return true;
  }

 private:

};

int main() {

  Solution().checkDistances("abaccb", {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

  return 0;
}
