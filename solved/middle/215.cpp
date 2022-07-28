#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, less<>> maxHeap;
    for (int x : nums)
      maxHeap.push(x);
    for (int _ = 0; _ < k - 1; _++)
      maxHeap.pop();
    return maxHeap.top();
  }

};

int main() {

  return 0;
}
