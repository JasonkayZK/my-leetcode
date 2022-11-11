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
#include <sstream>
#include <list>
#include <set>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <ctime>
#include <type_traits>
#include <cstdint>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> occurrences;
    for (auto &v : nums) {
      occurrences[v]++;
    }

    auto cmp = [](pair<int, int> x, pair<int, int> y) {
      return x.second > y.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (auto& [num, count] : occurrences) {
      if (pq.size() == k) {
        if (pq.top().second < count) {
          pq.pop();
          pq.emplace(num, count);
        }
      } else {
        pq.emplace(num, count);
      }
    }
    vector<int> ret;
    while (!pq.empty()) {
      ret.emplace_back(pq.top().first);
      pq.pop();
    }
    return ret;
  }

 private:

};

int main() {

  return 0;
}
