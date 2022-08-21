#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int res = 0, len = startTime.size();

    for (int i = 0; i < len; ++i) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i]) ++res;
    }

    return res;
  }

 private:

};

int main() {

  return 0;
}
