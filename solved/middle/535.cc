#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 private:
  unordered_map<int, string> dataBase;
  int id;

 public:
  Solution() {
    id = 0;
  }

  string encode(string longUrl) {
    id++;
    dataBase[id] = longUrl;
    return string("http://tinyurl.com/") + to_string(id);
  }

  string decode(string shortUrl) {
    int p = shortUrl.rfind('/') + 1;
    int key = stoi(shortUrl.substr(p, int(shortUrl.size()) - p));
    return dataBase[key];
  }
};

int main() {

  return 0;
}
