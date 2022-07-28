#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  string addStrings(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    if (m <= 0) return num2;
    if (n <= 0) return num1;

    int cur1 = m - 1, cur2 = n - 1, carry = 0;
    string res;
    while (cur1 >= 0 && cur2 >= 0) {
      int sum = num1[cur1--] - '0' + num2[cur2--] - '0' + carry;
      int cur = sum % 10;
      carry = sum / 10;
      res.push_back(cur + '0');
    }

    while (cur1 >= 0) {
      int sum = num1[cur1--] - '0' + carry;
      int cur = sum % 10;
      carry = sum / 10;
      res.push_back(cur + '0');
    }

    while (cur2 >= 0) {
      int sum = num2[cur2--] - '0' + carry;
      int cur = sum % 10;
      carry = sum / 10;
      res.push_back(cur + '0');
    }

    if (carry > 0) {
      res.push_back(carry + '0');
    }

    std::reverse(res.begin(), res.end());
    return res;
  }

};

int main() {

  return 0;
}
