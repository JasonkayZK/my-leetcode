#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<string> commonChars(vector<string> &&words) {
    vector<int> res(26), temp(26);
    fill(res.begin(), res.end(), INT_MAX);
    for (const auto &item : words) {
      int n = int(item.size());
      for (int i = 0; i < n; ++i) ++temp[item[i] - 'a'];
      for (int i = 0; i < 26; ++i) {
        res[i] = min(res[i], temp[i]);
      }
      fill(temp.begin(), temp.end(), 0);
    }

    vector<string> ret;
    for (int i = 0; i < 26; ++i) {
      if (res[i] == INT_MAX) continue;
      for (int j = 0; j < res[i]; ++j) {
        ret.emplace_back(string(1, 'a' + i));
      }
    }
    return ret;
  }

 private:

};

int main() {

  std::cout << Solution().commonChars({"bella", "label", "roller"});

  return 0;
}
