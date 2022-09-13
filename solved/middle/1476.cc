#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class SubrectangleQueries {
 public:

  explicit SubrectangleQueries(vector<vector<int>> &rectangle) : origin(rectangle) {
  }

  void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
    opt.push_back({row1, col1, row2, col2, newValue});
  }

  int getValue(int raw, int col) {
    for (int i = opt.size() - 1; i >= 0; --i) {
      if (col >= opt[i][1] && col <= opt[i][3] && raw >= opt[i][0] && raw <= opt[i][2]) {
        return opt[i][4];
      }
    }
    return origin[raw][col];
  }

 private:

  vector<vector<int>> origin;
  vector<vector<int>> opt;

};

int main() {

  return 0;
}
