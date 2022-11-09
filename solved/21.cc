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

  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    auto scott = new ListNode(0);
    auto cur = scott;

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        cur->next = list1;
        cur = cur->next;
        list1 = list1->next;
      } else {
        cur->next = list2;
        cur = cur->next;
        list2 = list2->next;
      }
    }
    while (list1 != nullptr) {
      cur->next = list1;
      cur = cur->next;
      list1 = list1->next;
    }
    while (list2 != nullptr) {
      cur->next = list2;
      cur = cur->next;
      list2 = list2->next;
    }

    return scott->next;
  }

 private:

};

int main() {

  return 0;
}
