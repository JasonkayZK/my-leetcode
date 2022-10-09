#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string reformatNumber(string number) {
    string digits;
    for (char ch : number) {
      if (isdigit(ch)) {
        digits.push_back(ch);
      }
    }

    int n = digits.size();
    int pt = 0;
    string ans;
    while (n) {
      if (n > 4) {
        ans += digits.substr(pt, 3) + "-";
        pt += 3;
        n -= 3;
      } else {
        if (n == 4) {
          ans += digits.substr(pt, 2) + "-" + digits.substr(pt + 2, 2);
        } else {
          ans += digits.substr(pt, n);
        }
        break;
      }
    }
    return ans;
  }

 private:

};

int main() {

  return 0;
}
