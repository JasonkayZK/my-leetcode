#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1, set2;
    for (auto& num : nums1) {
      set1.insert(num);
    }
    for (auto& num : nums2) {
      set2.insert(num);
    }
    return getIntersection(set1, set2);
  }

  vector<int> getIntersection(unordered_set<int>& set1, unordered_set<int>& set2) {
    if (set1.size() > set2.size()) {
      return getIntersection(set2, set1);
    }
    vector<int> intersection;
    for (auto& num : set1) {
      if (set2.count(num)) {
        intersection.push_back(num);
      }
    }
    return intersection;
  }

 private:

};

int main() {

  return 0;
}
