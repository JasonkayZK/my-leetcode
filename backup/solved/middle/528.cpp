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

    /* Method 1: STL
private:
    mt19937 rand; // 高质量随机数
    uniform_int_distribution<int> dis;  // 均匀分布
    vector<int> prefixSumArr; // 前缀和

public:
    Solution(vector<int> &w) : rand(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(prefixSumArr));
    }

    int pickIndex() {
        int x = dis(rand);   // 产生一个随机数，并且是均匀分布
        return lower_bound(prefixSumArr.begin(), prefixSumArr.end(), x) - prefixSumArr.begin();     // 二分查找
    }
     */

    /* Method 2: Prefix Array + Binary Search */
private:
    vector<int> prefixSumArr; // 前缀和

public:
    Solution(vector<int> &w) {
        partial_sum(w.begin(), w.end(), back_inserter(prefixSumArr));
    }

    int pickIndex() {
        int weight = rand() % prefixSumArr.back();
        return upper_bound(prefixSumArr.begin(), prefixSumArr.end(), weight) - prefixSumArr.begin();
    }
};

int main() {

    return 0;
}
