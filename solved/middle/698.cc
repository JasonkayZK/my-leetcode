#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0, std::plus<>());
    if (sum % k != 0) return false;
    int target = sum / k, n = int(nums.size());
    sort(nums.begin(), nums.end());
    vector<bool> visited(n);
    return dfs_helper(nums, n, target, k,
                      n - 1, 0, 0, visited);
  }

 private:

  bool dfs_helper(const vector<int> &nums, const int n, const int target, const int k,
                  int r, int cur, int cnt, vector<bool> &visited) {
    if (cnt == k) return true;
    if (cur == target) return dfs_helper(nums, n, target, k, n - 1, 0, cnt + 1, visited);
    for (int i = r; i >= 0; --i) {
      if (visited[i] || cur + nums[i] > target) continue;
      visited[i] = true;
      if (dfs_helper(nums, n, target, k, i - 1, cur + nums[i], cnt, visited)) return true;
      visited[i] = false;
      if (cur == 0) return false;
    }
    return false;
  }

};

int main() {

  return 0;
}
