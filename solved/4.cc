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

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size(), sum = m + n;
    if ((sum & 1) == 1) {
      return findKthElement(nums1, nums2, m, n, (sum + 1) / 2);
    } else {
      int l = findKthElement(nums1, nums2, m, n, sum / 2);
      int r = findKthElement(nums1, nums2, m, n, sum / 2 + 1);
      return (l + r) / 2.0;
    }
  }

 private:

  /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
   * 这里的 "/" 表示整除
   * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
   * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
   * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
   * 这样 pivot 本身最大也只能是第 k-1 小的元素
   * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
   * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
   * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
   */
  int findKthElement(vector<int> &nums1, vector<int> &nums2, int m, int n, int k) {
    int l_bound = 0, r_bound = 0;

    while (true) {
      if (l_bound >= m) {
        return nums2[r_bound + k - 1];
      }
      if (r_bound >= n) {
        return nums1[l_bound + k - 1];
      }
      if (k == 1) {
        return min(nums1[l_bound], nums2[r_bound]);
      }

      int newIndex1 = min(l_bound + k / 2 - 1, m - 1);
      int newIndex2 = min(r_bound + k / 2 - 1, n - 1);
      int pivot1 = nums1[newIndex1];
      int pivot2 = nums2[newIndex2];
      if (pivot1 <= pivot2) {
        k -= newIndex1 - l_bound + 1;
        l_bound = newIndex1 + 1;
      } else {
        k -= newIndex2 - r_bound + 1;
        r_bound = newIndex2 + 1;
      }
    }
  }

};

int main() {

  return 0;
}
