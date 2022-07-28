#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  bool canConstruct(string ransomNote, string magazine) {
    int m = ransomNote.size(), n = magazine.size();
    if (n < m) return false;

    vector<int> c_map(26, 0);
    for (const auto &item : ransomNote) {
      c_map[item - 'a']--;
    }
    for (const auto &item : magazine) {
      c_map[item - 'a']++;
    }
    for (const auto &item : c_map) {
      if (item < 0) return false;
    }

    return true;
  }

};

int main() {

  return 0;
}
