#include <utility>

#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class OrderedStream {
 public:
  OrderedStream(int n) {
    data = vector<string>(n);
    cur = 0;
  }

  vector<string> insert(int idKey, string value) {
    data[idKey - 1] = std::move(value);
    auto retData = vector<string>();
    if (idKey-1 == cur) {
      while (idKey - 1 < data.size() && !data[idKey - 1].empty()) {
        retData.emplace_back(string(data[idKey - 1]));
        data[idKey - 1] = "";
        ++idKey;
      }
      cur = idKey-1;
    }
    return retData;
  }

 private:
  vector<string> data;
  int cur;
};

int main() {

  auto os = new OrderedStream(5);
  std::cout << os->insert(3, "ccccc") << "\n"; // 插入 (3, "ccccc")，返回 []
  std::cout << os->insert(1, "aaaaa") << "\n"; // 插入 (1, "aaaaa")，返回 ["aaaaa"]
  std::cout << os->insert(2, "bbbbb") << "\n"; // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
  std::cout << os->insert(5, "eeeee") << "\n"; // 插入 (5, "eeeee")，返回 []
  std::cout << os->insert(4, "ddddd") << "\n"; // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]

  return 0;
}
