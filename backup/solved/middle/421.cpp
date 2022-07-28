#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Trie {
 private:

  static constexpr int HIGHEST_BIT = 30;

  // 左子树指向表示 0 的子节点
  Trie *left = nullptr;

  // 右子树指向表示 1 的子节点
  Trie *right = nullptr;

 public:

  Trie() = default;

  static Trie *buildTrieTree(vector<int> &nums) {
    Trie *root = new Trie();
    for (int num : nums) {
      add(root, num);
    }
    return root;
  }

  static void add(Trie *root, int num) {
    auto cur = root;
    for (int i = HIGHEST_BIT; i >= 0; --i) {
      if ((num >> i) & 1) {
        if (cur->right == nullptr) {
          cur->right = new Trie();
        }
        cur = cur->right;
      } else {
        if (cur->left == nullptr) {
          cur->left = new Trie();
        }
        cur = cur->left;
      }
    }
  }

  int findMaxInTrieTree(int num) {
    auto cur = this;
    int res = 0;

    for (int i = HIGHEST_BIT; i >= 0; --i) {
      // num从左数第i位为1，异或更大的应当选取0
      if ((num >> i) & 1) {
        if (cur->left) {
          res = res * 2 + 1;
          cur = cur->left;
        } else {
          res *= 2;
          cur = cur->right;
        }
      } else {
        if (cur->right) {
          res = res * 2 + 1;
          cur = cur->right;
        } else {
          res *= 2;
          cur = cur->left;
        }
      }
    }

    return res;
  }

};

/**
 * Solution: Trie Tree
 */
class Solution {

 public:
  int findMaximumXOR(vector<int> &nums) {
    auto root = Trie::buildTrieTree(nums);
    int res = 0;
    for (auto num : nums) {
      res = max(res, root->findMaxInTrieTree(num));
    }
    return res;
  }
};

int main() {
  cout << Solution().findMaximumXOR(vector<int>() = {
      3, 10, 5, 25, 2, 8
  }) << endl;
  cout << Solution().findMaximumXOR(vector<int>() = {
      0
  }) << endl;
  cout << Solution().findMaximumXOR(vector<int>() = {
      2, 4
  }) << endl;
  cout << Solution().findMaximumXOR(vector<int>() = {
      8, 10, 2
  }) << endl;
  cout << Solution().findMaximumXOR(vector<int>() = {
      14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70
  }) << endl;

  return 0;
}






