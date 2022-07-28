#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int halfQuestions(vector<int> &questions) {
    int cnt[1001];
    fill(cnt, cnt + 1001, 0);

    for (const auto &item : questions) cnt[item]++;

    sort(cnt, cnt + 1001);

    int n = int(questions.size()) / 2, res = 0;

    for (int i = 1000; i >= 0; --i) {
      if (n <= 0) return res;
      n -= cnt[i];
      res++;
    }

    return res;
  }

 private:

};

int main() {

  return 0;
}
