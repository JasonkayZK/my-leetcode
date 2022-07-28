#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    int m = int(rolls.size());

    int offset = mean * (m + n) - std::accumulate(rolls.begin(), rolls.end(), 0);
    if (offset > 6 * n || offset < n) return {};

    vector<int> ret(n, 1);
    offset -= n;

    int cur = 0;
    while (offset > 0) {
      int offset_add = offset >= 6 ? 5 : offset;
      ret[cur] += offset_add;
      offset -= offset_add;
      cur++;
    }

    return ret;
  }

};

int main() {

  return 0;
}
