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
    /* Method 1: Brute Force
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0, len = arr.size();
        for (int start = 0; start < len; ++start) {
            for (int curLen = 1; start + curLen <= len; curLen += 2) {
                int end = start + curLen - 1;
                for (int i = start; i <= end; ++i) {
                    sum += arr[i];
                }
            }
        }
        return sum;
    }
     */

    /* Method 2: Prefix Array
    int sumOddLengthSubarrays(vector<int> &arr) {
        int len = arr.size();
        auto prefixSum = new int[len + 1];
        for (int i = 0; i < len; ++i) {
            prefixSum[i+1] = prefixSum[i] + arr[i];
        }

        int res = 0;
        for (int start = 0; start < len; ++start) {
            for (int curLen = 1; start + curLen <= len; curLen += 2) {
                int end = start + curLen - 1;
                res += prefixSum[end + 1] - prefixSum[start];
            }
        }
        return res;
    }
     */

    /* Method 3: Math */
    int sumOddLengthSubarrays(vector<int> &arr) {
        int sum = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            int leftCount = i, rightCount = n - i - 1;
            int leftOdd = (leftCount + 1) / 2;
            int rightOdd = (rightCount + 1) / 2;
            int leftEven = leftCount / 2 + 1;
            int rightEven = rightCount / 2 + 1;
            sum += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);
        }
        return sum;
    }

};

int main() {

    return 0;
}
