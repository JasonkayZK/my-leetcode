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

  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto scott = new ListNode(0, head);
    auto fast = head;

    int i = n;
    while (i > 0 && fast != nullptr) {
      fast = fast->next;
      --i;
    }

    auto slow = scott;
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;
    return scott->next;
  }

 private:

};

int main() {

  return 0;
}
