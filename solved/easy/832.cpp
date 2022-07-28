#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
    int n = image.size();
    for (int i = 0; i < n; i++) {
      int left = 0, right = n - 1;
      while (left < right) {
        if (image[i][left] == image[i][right]) {
          image[i][left] ^= 1;
          image[i][right] ^= 1;
        }
        left++;
        right--;
      }
      if (left == right) {
        image[i][left] ^= 1;
      }
    }
    return image;
  }

};

int main() {

  return 0;
}
