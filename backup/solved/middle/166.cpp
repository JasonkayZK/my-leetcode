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

using PII = pair<int, int>;
using LL = long long;
using PIC = pair<int, char>;

// Definition for a binary tree node.
class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
class ListNode {
 public:
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_vec(vector<int> arr) {
  std::for_each(arr.begin(), arr.end(), [](const auto &i) { std::cout << i << " "; });
  cout << "\n";
}

void swap(vector<int> &nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

class Solution {
 public:
  using LL = long long;

  string fractionToDecimal(int numerator, int denominator) {
    LL n = numerator, d = denominator;
    string ret;

    // 判断负数
    if (n * d < 0) ret += "-";

    // 计算整数部分
    LL a = n / d;
    if (a < 0) a *= -1;
    ret += to_string(a);

    if (n < 0) n *= -1;
    if (d < 0) d *= -1;

    // 计算小数部分
    n %= d;
    if (n == 0) {
      // 无小数
      return ret;
    }

    ret += ".";
    // 连除
    // 哈希表记录是否有数组第二次出现
    unordered_map<int, int> st;
    string t;
    int index = 0;
    while (n && !st.count(n)) {
      st[n] = index++;
      n *= 10;
      t.push_back((char) (n / d + '0'));
      n %= d;
    }

    if (n != 0) {
      // 说明出现了循环，此时对循环部分 [st[n], index] 加括号
      ret += t.substr(0, st[n]) + "(" + t.substr(st[n]) + ")";
    } else {
      ret += t;
    }
    return ret;
  }
};

int main() {

  return 0;
}
