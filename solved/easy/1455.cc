#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int isPrefixOfWord(string sentence, string searchWord) {
    auto words = split(sentence, ' ');
    int res = -1;
    for (int i = 0; i < words.size(); ++i) {
      if (words[i].rfind(searchWord, 0) == 0) return i + 1;
    }
    return res;
  }

 private:

  static vector<string> split(const string &s, const char delimiter) {
    vector<string> tokens;
    string token;
    istringstream token_stream(s);
    while (getline(token_stream, token, delimiter)) {
      tokens.push_back(token);
    }
    return tokens;
  }
};

int main() {

  return 0;
}
