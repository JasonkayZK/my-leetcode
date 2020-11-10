/*
 * @lc app=leetcode.cn id=326 lang=java
 *
 * [326] 3的幂
 */

/* Test Case

-3
0
1
2
3
9
23
27
45
243

*/

/* Method 1: Iteration

    Time: O(logn)
    Space: O(1)

class Solution {
    public boolean isPowerOfThree(int n) {
        if (n <= 0) {return false;}
        while (n % 3 == 0) {n /= 3;}
        return n == 1;
    }
}
*/

/* Method 2: Math

    Time: O(1)
    Space: O(1)

*/
class Solution {
    public boolean isPowerOfThree(int n) {
        double a = Math.log(n) / Math.log(3);
        return Math.abs(a - Math.rint(a)) <= 0.00000000000001;
    }
}


