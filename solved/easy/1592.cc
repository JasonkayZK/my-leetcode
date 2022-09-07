#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string reorderSpaces(string text) {
    vector<string> words;
    stringstream in(text);
    string word;
    int word_len = 0;

    while (in >> word) {
      word_len += int(word.size());
      words.emplace_back(word);
    }

    string ans;
    int n_words = int(words.size());
    if (n_words == 1) {
      ans += words[0];
    } else {
      // Each len of the middle space
      string space((text.size() - word_len) / (words.size() - 1), ' ');
      for (int i = 0; i < n_words - 1; ++i) {
        ans += words[i] + space;
      }
      ans += words[n_words - 1];
    }

    return ans + string(text.size() - ans.size(), ' ');
  }

 private:

};

int main() {

  return 0;
}
