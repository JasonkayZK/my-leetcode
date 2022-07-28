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

/* Method 1: Heap
class Solution {
private:

public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res(k,0);
        if (k <= 0) return res;

        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            pq.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            if (pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            res[i] = pq.top();
            pq.pop();
        }
        return res;
    }
};
*/

/* Method 2: Quick Sort */
// 快排，pivot=k时，停止
class Solution {
 private:
  vector<int> res;
  int pos;

  void quickSort(vector<int> &nums, int l, int r) {
    if (l <= r) {
      int pivot = partition(nums, l, r);
      if (pivot == pos) {
        for (int i = 0; i < pivot; i++) res.push_back(nums[i]);
        return;
      } else if (pivot < pos) {
        quickSort(nums, pivot + 1, r);
      } else {
        quickSort(nums, l, pivot - 1);
      }
    }

  }

  int partition(vector<int> &nums, int l, int r) {
    int pivotVal = nums[l];
    while (l < r) {
      while (nums[r] >= pivotVal && r > l) r--;
      nums[l] = nums[r];
      while (nums[l] <= pivotVal && l < r) l++;
      nums[r] = nums[l];
    }
    nums[l] = pivotVal;
    return l;
  }

 public:
  vector<int> smallestK(vector<int> &arr, int k) {
    int len = arr.size();
    pos = k;
    quickSort(arr, 0, len - 1);
    return res;
  }
};
