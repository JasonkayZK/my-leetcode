#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

  int maxConsecutiveChar(string &answerKey, int k, char c) {
    int n = answerKey.length();
    int ans = 0;

    for (int left = 0, right = 0, sum = 0; right < n; ++right) {
      sum += answerKey[right] != c; // right window slides to right

      while (sum > k) { // left window slides to right
        sum -= answerKey[left++] != c;
      }
      ans = max(ans, right - left + 1);
    }

    return ans;
  }

 public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    return max(maxConsecutiveChar(answerKey, k, 'T'), maxConsecutiveChar(answerKey, k, 'F'));
  }
};

int main() {

  return 0;
}
