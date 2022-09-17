#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int rectangleArea(vector<vector<int>> &rectangles) {
    vector<int> lines;
    for (const auto &item : rectangles) {
      lines.emplace_back(item[0]);
      lines.emplace_back(item[2]);
    }
    sort(lines.begin(), lines.end());

    long long res = 0;
    int n = int(lines.size());
    for (int i = 1; i < n; ++i) {
      int l = lines[i - 1], r = lines[i];
      if (l == r) continue; // the same x line

      vector<pair<int, int>> cols;
      for (vector<int> &v : rectangles) {
        if (v[0] <= l && v[2] >= r) cols.emplace_back(v[1], v[3]);
      }
      sort(cols.begin(), cols.end());

      int up = -1, down = -1;
      long long cur = 0;
      for (pair<int, int> &p : cols) {
        if (p.first > up) { // not continuous
          cur += up - down;
          down = p.first;
          up = p.second;
        } else if (p.second > up) { // continuous
          up = p.second;
        }
      }
      cur += up - down; // current final height
      cur *= r - l; // calculate space
      cur %= MOD;
      res += cur; // sum total space
      res %= MOD;
    }

    return res;
  }

 private:

  int MOD = 1e9 + 7;

};

int main() {

  return 0;
}
