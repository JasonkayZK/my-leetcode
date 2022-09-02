#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> finalPrices(vector<int> &prices) {
    int size = int(prices.size());
    if (size <= 1) return prices;

    stack<int> lastMin{};
    vector<int> res(size);
    for (int i = size - 1; i >= 0; i--) {
      while (!lastMin.empty() && lastMin.top() > prices[i]) lastMin.pop();
      res[i] = lastMin.empty() ? prices[i] : prices[i] - lastMin.top();
      lastMin.emplace(prices[i]);
    }

    return res;
  }

 private:

};

int main() {

  return 0;
}
