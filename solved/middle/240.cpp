#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    if (m <= 0) return false;
    int n = matrix[0].size();
    if (n <= 0)return false;

    int raw = 0, col = n - 1;
    while (raw < m && col >= 0) {
      if (target == matrix[raw][col]) return true;
      else if (target > matrix[raw][col]) raw++;
      else col--;
    }
    return false;
  }

};

int main() {

  return 0;
}
