#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string solveEquation(string equation) {
    int x = 0, num = 0, len = int(equation.length());

    for (int i = 0, op = 1; i < len;) {
      if (equation[i] == '+') {
        op = 1;
        ++i;
      } else if (equation[i] == '-') {
        op = -1;
        ++i;
      } else if (equation[i] == '=') {
        x *= -1;
        num *= -1;
        op = 1;
        ++i;
      } else {
        int j = i;
        while (j < len && equation[j] != '+' && equation[j] != '-' && equation[j] != '=') j++;
        if (equation[j - 1] == 'x') x += (i < j - 1 ? stoi(equation.substr(i, j - 1)) : 1) * op;
        else num += stoi(equation.substr(i, j)) * op;
        i = j;
      }
    }

    if (x == 0) return num == 0 ? "Infinite solutions" : "No solution";
    else return "x=" + to_string(num / -x);
  }

 private:

};

int main() {

  return 0;
}
