#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string decodeMessage(string key, string message) {
    int ord[26] = {0}, cnt = 0;
    for (char c : key) if (c >= 'a' && c <= 'z' && ord[c - 'a'] == 0) ord[c - 'a'] = ++cnt;
    for (char &c : message) if (c >= 'a' && c <= 'z') c = ord[c - 'a'] - 1 + 'a';
    return message;
  }

 private:

};

int main() {

  return 0;
}
