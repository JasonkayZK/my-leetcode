#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 public:
  Node *construct(vector<vector<int>> &grid) {
    return recursion(0, 0, grid.size() - 1, grid.size() - 1, grid);
  }

  Node *recursion(int top, int left, int bottom, int right, vector<vector<int>> &grid) {
    Node *res = new Node();

    if (checkLeaf(top, left, bottom, right, grid)) {
      res->val = grid[top][left];
      res->isLeaf = true;
      return res;
    }

    res->isLeaf = false;
    res->val = 1;

    res->topLeft = recursion(top, left, top + (bottom - top) / 2, left + (right - left) / 2, grid);
    res->topRight = recursion(top, right - (right - left) / 2, top + (bottom - top) / 2, right, grid);
    res->bottomLeft = recursion(bottom - (bottom - top) / 2, left, bottom, left + (right - left) / 2, grid);
    res->bottomRight = recursion(bottom - (bottom - top) / 2, right - (right - left) / 2, bottom, right, grid);

    return res;
  }

  bool checkLeaf(int top, int left, int bottom, int right, vector<vector<int>> &grid) {
    //传入左上 右下 坐标，验证方块内是否一致
    int same = grid[top][left];

    for (int i = top; i <= bottom; ++i) {
      for (int j = left; j <= right; ++j) {
        if (grid[i][j] != same) return false;
      }
    }

    return true;
  }
};

int main() {
  int a = 666;
  vector<int> b({1, 2, 3});
  string c = "hello world";

  // after
  debug(a, b, c);  // a=666, b=[ 1, 2, 3, ], c=hello world

  return 0;
}
