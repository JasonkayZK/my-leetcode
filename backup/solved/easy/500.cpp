#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <queue>
#include <set>
#include <random>

using namespace std;

class Solution {
 public:
  vector<string> findWords(vector<string> &words) {
    vector<string> ans;
    string rowIdx = "12210111011122000010020202";
    for (auto &word : words) {
      bool isValid = true;
      char idx = rowIdx[tolower(word[0]) - 'a'];
      for (int i = 1; i < word.size(); ++i) {
        if (rowIdx[tolower(word[i]) - 'a'] != idx) {
          isValid = false;
          break;
        }
      }
      if (isValid) {
        ans.emplace_back(word);
      }
    }
    return ans;
  }
};
