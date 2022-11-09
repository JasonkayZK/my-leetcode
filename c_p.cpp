#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

int factorial(int n) {
  int fc = 1;
  for (int i = 1; i <= n; ++i) fc *= i;
  return fc;
}

vector<vector<int>> init_c(int m, int n) {
  vector<vector<int>> res(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i && j <= m; j++) {
      if (j == 0) res[i][j] = 1;
      else res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
  }

  return res;
}

vector<vector<int>> init_p(int m, int n) {

  vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
  for (int i = m; i >= 0; --i) {
    for (int j = i; j >= 0; --j) {
      if (j == i) res[i][j] = factorial(i);
      else if (j == 0) res[i][j] = 1;
      else if (j == 1) res[i][j] = i;
      else res[i][j] = res[i][j - 1] * j;
    }
  }

}

class Solution {
 private:

 public:

  int paintingPlan(int n, int k) {
    if (k == 0) return 1;
    if (k < n) return 0;
    if (k == n * n) return 1;

    auto C = init_c(10, 10);
    int res = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (n * i + n * j - i * j == k) {
          res += C[n][i] * C[n][j];
        }
      }
    }

    return res;
  }

};

int main() {

  int m = 2, n = 4;
  auto c = init_c(m, n);
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      cout << "C(" << i << "," << j << "): " << c[i][j] << endl;
    }
  }

  auto p = init_p(m, n);
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= i; ++j) {
      cout << "P(" << i << "," << j << "): " << p[i][j] << endl;
    }
  }

  return 0;
}
