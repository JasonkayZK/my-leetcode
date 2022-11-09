#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string makeLargestSpecial(string s) {
    if (s.size() <= 2) return s;

    int cnt = 0, left = 0;
    vector<string> subs;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        ++cnt;
      } else {
        --cnt;
        if (cnt == 0) {
          subs.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
          left = i + 1;
        }
      }
    }

    sort(subs.begin(), subs.end(), greater<string>{});
    string ans = accumulate(subs.begin(), subs.end(), ""s);
    return ans;
  }

 private:

};

int main() {

  return 0;
}
