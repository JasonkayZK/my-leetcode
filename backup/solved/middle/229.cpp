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
  vector<int> majorityElement(vector<int> &nums) {
    vector<int> ans;
    int elem1 = 0, elem2 = 0, vote1 = 0, vote2 = 0;

    // Moore Vote
    for (const auto &elem : nums) {
      if (vote1 > 0 && elem == elem1) { //如果该元素为第一个元素，则计数加1
        vote1++;
      } else if (vote2 > 0 && elem == elem2) { //如果该元素为第二个元素，则计数加1
        vote2++;
      } else if (vote1 == 0) { // 选择第一个元素
        elem1 = elem;
        vote1++;
      } else if (vote2 == 0) { // 选择第二个元素
        elem2 = elem;
        vote2++;
      } else { //如果三个元素均不相同，则相互抵消1次
        vote1--;
        vote2--;
      }
    }

    // Vote Count
    int cnt1 = 0, cnt2 = 0;
    for (auto &elem : nums) {
      if (vote1 > 0 && elem == elem1) {
        cnt1++;
      }
      if (vote2 > 0 && elem == elem2) {
        cnt2++;
      }
    }

    // Answer Check
    if (vote1 > 0 && cnt1 > nums.size() / 3) {
      ans.push_back(elem1);
    }
    if (vote2 > 0 && cnt2 > nums.size() / 3) {
      ans.push_back(elem2);
    }

    return ans;
  }
};
