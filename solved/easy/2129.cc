#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string capitalizeTitle(string title) {
    int n = title.size();
    int l = 0, r = 0;   // 单词左右边界（左闭右开）
    title.push_back(' ');   // 避免处理末尾的边界条件
    while (r < n) {
      while (title[r] != ' ') {
        ++r;
      }
      // 对于每个单词按要求处理
      if (r - l > 2) {
        title[l] = toupper(title[l]);
        ++l;
      }
      while (l < r) {
        title[l] = tolower(title[l]);
        ++l;
      }
      l = r + 1;
      ++r;
    }
    title.pop_back();
    return title;
  }

 private:

};

int main() {

  return 0;
}
