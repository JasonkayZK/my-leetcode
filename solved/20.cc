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

class Solution {
 public:

  bool isValid(string s) {
    stack<char> stk;

    for (const auto &c : s) {
      if (c == '}') {
        if (stk.empty() || stk.top() != '{') return false;
        else stk.pop();
      } else if (c == ')') {
        if (stk.empty() || stk.top() != '(') return false;
        else stk.pop();
      } else if (c == ']') {
        if (stk.empty() || stk.top() != '[') return false;
        else stk.pop();
      } else {
        stk.push(c);
      }
    }

    return stk.empty();
  }

 private:

};

int main() {

  return 0;
}
