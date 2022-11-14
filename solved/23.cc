  #include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto scott = new ListNode(0);
    auto cur = scott;
    int n = lists.size();
    if (n <= 0) {
      return scott->next;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
      auto cur_list = lists[i];
      while (cur_list != nullptr) {
        pq.push(cur_list->val);
        cur_list = cur_list->next;
      }
    }

    while (!pq.empty()) {
      cur->next = new ListNode(pq.top());
      pq.pop();
      cur = cur->next;
    }
    return scott->next;
  }
};

int main() { return 0; }
