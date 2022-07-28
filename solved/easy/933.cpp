#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 private:

 public:

};

class RecentCounter {
 public:
  RecentCounter() = default;

  int ping(int t) {
    if (q.empty()) {
      q.emplace(t);
      return 1;
    }

    while (!q.empty() && t - q.front() > 3000) q.pop();
    q.emplace(t);
    return q.size();
  }

 private:
  queue<int> q;
};

int main() {

  return 0;
}
