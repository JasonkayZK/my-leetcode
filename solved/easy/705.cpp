#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method: Zipper */
class MyHashSet {
 private:
  static const int base = 821; // prime number

  vector<list<int>> s;

  static int hash(int key) {
    return key % base;
  }

  auto _find_item(int hashed_key) {
    int k = hash(hashed_key);

    return std::find_if(s[k].begin(), s[k].end(), [&hashed_key](auto x) {
      return x == hashed_key;
    });
  }

 public:

  MyHashSet() : s(base) {}

  void add(int key) {
    int k = hash(key);
    auto it = _find_item(key);

    if (it == s[k].end()) { // not found
      s[k].push_back(key);
    }
  }

  void remove(int key) {
    int k = hash(key);
    auto it = _find_item(key);

    if (it != s[k].end()) { // not found
      s[k].remove(key);
    }
  }

  bool contains(int key) {
    int k = hash(key);

    return _find_item(key) != s[k].end();
  }

};

int main() {

  return 0;
}
