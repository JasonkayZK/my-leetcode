#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
    vector<int> res1, res2;
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                        std::inserter(res1, std::begin(res1)));
    std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(),
                        std::inserter(res2, std::begin(res2)));
    return {res1, res2};
  }

};

int main() {

  return 0;
}
