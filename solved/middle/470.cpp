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
    int rand10() {
        while (true) {
            int x = rand7();
            int num = (x - 1) * 7 + rand7();        //rand7()每次调用的值都不同，故不要用变量来存
            if (num <= 40) return num % 10 + 1;     //大于 40 拒绝采样，

            x = num - 40;                           //此时 x = rand9()
            num = (x - 1) * 7 + rand7();            // 8 * 7 + 7 = 63
            if (num <= 60) return num % 10 + 1;     //大于 60 拒绝采样

            x = num - 60;                           //此时 x = rand3()
            num = (x - 1) * 7 + rand7();            // 2 * 7 + 7 = 21
            if (num <= 20) return num % 10 + 1;     //大于 20 拒绝采样
        }
    }
};


int main() {

    return 0;
}
