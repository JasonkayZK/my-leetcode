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

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto scott = new ListNode(0, l1);
    auto prev = scott;

    int flag = 0, cnt_v;
    while (l1 != nullptr && l2 != nullptr) {
      cnt_v = l1->val + l2->val + flag;
      flag = cnt_v / 10;
      prev->next = new ListNode(cnt_v % 10);
      prev = prev->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1 != nullptr) {
      cnt_v = l1->val + flag;
      flag = cnt_v / 10;
      prev->next = new ListNode(cnt_v % 10);
      prev = prev->next;
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      cnt_v = l2->val + flag;
      flag = cnt_v / 10;
      prev->next = new ListNode(cnt_v % 10);
      prev = prev->next;
      l2 = l2->next;
    }
    if (flag != 0) {
      prev->next = new ListNode(flag);
    }
    return scott->next;
  }

 private:

};

int main() {

  return 0;
}
