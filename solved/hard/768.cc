#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxChunksToSorted(vector<int> &arr) {
    stack<int> st{};
    for (const auto &item : arr) {
      if (st.empty() || st.top() <= item) {
        st.emplace(item);
      } else {
        int mx = st.top();
        st.pop();
        while (!st.empty() && st.top() > item) {
          st.pop();
        }
        st.emplace(mx);
      }
    }
    return st.size();
  }

 private:

};

int main() {

  return 0;
}
