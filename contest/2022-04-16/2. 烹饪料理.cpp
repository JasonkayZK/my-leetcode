#include "../../utils/utils.h"
#include "../../data_structure/list.h"
#include "../../data_structure/tree.h"
#include "../../data_structure/trie.h"
#include "../../data_structure/segment_tree.h"

class Solution {
 private:

  const int cook_material_type = 5;

  int res;

  bool can_cook(vector<int> &materials, vector<vector<int>> &cookbooks, int cur) {
    for (int i = 0; i < cook_material_type; ++i) {
      if (materials[i] - cookbooks[cur][i] < 0) return false;
    }
    return true;
  }

  void cook(vector<int> &materials, vector<vector<int>> &cookbooks, int cur) {
    for (int i = 0; i < cook_material_type; ++i) {
      materials[i] -= cookbooks[cur][i];
    }
  }

  void revert_cook(vector<int> &materials, vector<vector<int>> &cookbooks, int cur) {
    for (int i = 0; i < cook_material_type; ++i) {
      materials[i] += cookbooks[cur][i];
    }
  }

  void dfs_helper(vector<int> &materials, vector<vector<int>> &cookbooks,
                  vector<vector<int>> &attribute, int cur_res, int cur_limit, int cur, int size, int limit) {

    if (cur >= size) {
      return;
    }

    if (can_cook(materials, cookbooks, cur)) {
      // cook current
      cur_res += attribute[cur][0];
      cur_limit += attribute[cur][1];
      cook(materials, cookbooks, cur);
      if (cur_limit >= limit) { // update result
        res = max(res, cur_res);
      }

      // dfs
      dfs_helper(materials, cookbooks, attribute, cur_res, cur_limit, cur + 1, size, limit);

      // backtrace
      cur_res -= attribute[cur][0];
      cur_limit -= attribute[cur][1];
      revert_cook(materials, cookbooks, cur);
    }

    // not cook this
    dfs_helper(materials, cookbooks, attribute, cur_res, cur_limit, cur + 1, size, limit);
  }

 public:

  int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks,
                  vector<vector<int>> &attribute, int limit) {
    res = -1;
    dfs_helper(materials, cookbooks, attribute, 0, 0, 0, cookbooks.size(), limit);
    return res;
  }

};

int main() {

  return 0;
}
