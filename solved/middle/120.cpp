#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  int minimumTotal(vector<vector<int>> &triangle) {
    vector<int> dp(triangle.back());
    for (int i = triangle.size() - 2; i >= 0; i--)
      for (int j = 0; j <= i; j++)
        dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
    return dp[0];
  }

};

int main() {

  return 0;
}
