#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string orderlyQueue(string s, int k) {
    if (k == 1) {
      string res = s;
      int len = int(s.size());
      for (int i = 0; i < len - 1; ++i) {
        s = put_char_to_end(s, 0);
        cout << "put i: " << i << ", temp: " << s << endl;
        res = min(res, s);
      }
      return res;
    } else {
      sort(s.begin(), s.end());
      return s;
    }
  }

 private:

  static string put_char_to_end(string s, int i) {
    char c = s[i];
    return s.substr(0, i) + s.substr(i + 1, s.size()) + c;
  }

};

int main() {

  Solution().orderlyQueue("cba", 1);

  return 0;
}
