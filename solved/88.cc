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

  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int cur = nums1.size() - 1;
    --m, --n;

    while (m >= 0 && n >= 0) {
      if (nums1[m] >= nums2[n]) {
        nums1[cur] = nums1[m];
        --m;
      } else {
        nums1[cur] = nums2[n];
        --n;
      }
      --cur;
    }
    while (m >= 0) {
      nums1[cur] = nums1[m];
      --m;
      --cur;
    }
    while (n >= 0) {
      nums1[cur] = nums2[n];
      --n;
      --cur;
    }
  }

 private:

};

int main() {

  return 0;
}
