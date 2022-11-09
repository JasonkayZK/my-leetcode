#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    unordered_map<int, vector<int>> groups;
    int n = int(groupSizes.size());
    for (int i = 0; i < n; i++) {
      int size = groupSizes[i];
      groups[size].emplace_back(i);
    }

    vector<vector<int>> groupList;
    for (auto &[size, people] : groups) {
      int groupCount = people.size() / size;
      for (int i = 0; i < groupCount; i++) {
        vector<int> group;
        int start = i * size;
        for (int j = 0; j < size; j++) {
          group.emplace_back(people[start + j]);
        }
        groupList.emplace_back(group);
      }
    }
    return groupList;
  }

 private:

};

int main() {

  return 0;
}
