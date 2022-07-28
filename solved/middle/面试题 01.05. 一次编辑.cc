#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool oneEditAway(string first, string second) {
    auto m = first.size(), n = second.size();

    if (m == n) return modifyCheck(first, second, m);
    else if (m - n == 1) return deleteCheck(first, second, m);
    else if (m - n == -1) return addCheck(first, second, m + 1);
    else return false;
  }

 private:

  bool modifyCheck(const string &x, const string &y, unsigned long n) {
    bool opted = false;

    for (int i = 0; i < n; ++i) {
      if (x[i] != y[i]) {
        if (opted) return false;
        else opted = true;
      }
    }
    return true;
  }

  bool deleteCheck(const string &x, const string &y, unsigned long n) {
    bool opted = false;

    int l = 0, r = 0;
    while (l < n && r < n) {
      if (x[l] != y[r]) {
        if (opted) return false;
        else {
          ++l;
          opted = true;
          continue;
        }
      }
      ++l;
      ++r;
    }
    return true;
  }

  bool addCheck(const string &x, const string &y, unsigned long n) {
    bool opted = false;

    int l = 0, r = 0;
    while (l < n && r < n) {
      if (x[l] != y[r]) {
        if (opted) return false;
        else {
          ++r;
          opted = true;
          continue;
        }
      }
      ++l;
      ++r;
    }
    return true;
  }

};

int main() {

  return 0;
}
