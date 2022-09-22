#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int ans = 0;
    for(int i = 0; i < items.size(); ++i)
      if(items[i][mt[ruleKey]] == ruleValue) ++ans;
    return ans;
  }

 private:

  unordered_map<string, short> mt = {
      {"type",0},{"color",1},{"name",2}
  };

};

int main() {

  return 0;
}
