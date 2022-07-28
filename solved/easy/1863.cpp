#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method 1: backtrace
class Solution {
private:

    int res;

    void helper(int cur, int sum, vector<int>& nums) {
        if (cur == nums.size()) res += sum;
        else {
            helper(cur+1, sum, nums);
            helper(cur+1, sum ^ nums[cur], nums);
        }
    }

public:

    int subsetXORSum(vector<int>& nums) {
        res = 0;
        int n = int(nums.size());
        if (n <= 0) return res;

        for (int i = 0; i < n; ++i) {
            helper(i+1, nums[i], nums);
        }

        return res;
    }

};
*/

/* Method 2: Math */
class Solution {
 private:

 public:

  int subsetXORSum(vector<int> &nums) {
    return (std::accumulate(nums.begin(), nums.end(), 0, bit_or()) << (nums.size() - 1));
  }

};

int main() {

  return 0;
}
