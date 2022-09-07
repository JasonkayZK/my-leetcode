#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2) {
    map<int, int> mp;

    for (const auto &item : items1) {
      mp.emplace(make_pair(item[0], item[1]));
    }
    for (const auto &item : items2) {
      if (mp.count(item[0]) > 0) {
        mp[item[0]] += item[1];
      } else {
        mp.emplace(make_pair(item[0], item[1]));
      }
    }

    vector<vector<int>> res;
    for (const auto &item : mp) {
      res.push_back({item.first, item.second});
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
