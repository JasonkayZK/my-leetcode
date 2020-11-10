/*
 * @lc app=leetcode.cn id=461 lang=java
 *
 * [461] 汉明距离
 */


/* Test Case:

1
4
0
2
32145
1345

*/

/* Method 1: Bit Operation [Best]

    Time: O(log(n))
    Space: O(1)

class Solution {
    public int hammingDistance(int x, int y) {
        int res = 0;
        int xor = x ^ y;

        while (xor > 0) {
            xor = xor & (xor - 1);
            res++;
        }
        return res;
    }
}
*/

/* Method 2: Bit Operation [Best]

    Time: O(log(n))
    Space: O(1)
*/
class Solution {
    public int hammingDistance(int x, int y) {
        int res = 0;

        while (x != 0 || y != 0) {
            res += (x & 1) ^ (y & 1);

            x >>>= 1;
            y >>>= 1;
        }
        return res;
    }
}



