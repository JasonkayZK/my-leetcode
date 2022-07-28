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

using namespace std;

using LL = long long;

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    LL res = 1;
    for (int i = 1; i < n; ++i) {
      for (auto &prime : primes) {
        pq.push(prime * res);
      }
      res = pq.top();
      pq.pop();
      while (pq.size() && res == pq.top()) pq.pop();
    }
    return (int) res;
  }
};
