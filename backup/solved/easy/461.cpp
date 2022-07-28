#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Solution {
 public:
/* Solution 1: default
    int hammingDistance(int x, int y) {
        int c = x^y;
        int res = 0;
        while (c) {
            res += c & 1;
            c >>= 1;
        }
        return res;
    }
*/

/* Solution 2: Brian Kernighan
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s) {
            s &= s - 1;
            ret++;
        }
        return ret;
    }
*/

/* Solution 3: 分治 */
  int hammingDistance(int x, int y) {
    int c;
    c = x ^ y;
    c = (c & 0x55555555) + ((c >> 1) & 0x55555555);
    c = (c & 0x33333333) + ((c >> 2) & 0x33333333);
    c = (c & 0x0f0f0f0f) + ((c >> 4) & 0x0f0f0f0f);
    c = (c & 0x00ff00ff) + ((c >> 8) & 0x00ff00ff);
    c = (c & 0x0000ffff) + ((c >> 16) & 0x0000ffff);
    return c;
  }

};
