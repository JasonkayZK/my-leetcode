/*
 * @lc app=leetcode.cn id=509 lang=java
 *
 * [509] 斐波那契数
 */

/* Test Case:

0
1
2
3
4
16

*/

/* Method 1: Recursive
class Solution {
    public int fib(int N) {
        if (N < 0) throw new RuntimeException("0 <= N <= 30");
        if (N == 0) return 0;
        if (N == 1) return 1;
        return fib(N - 1) + fib(N - 2);
    }
}
 */

/* Method 2: DP */
class Solution {
    public int fib(int N) {
        if (N < 0) throw new RuntimeException("0 <= N <= 30");
        if (N == 0) return 0;
        if (N == 1) return 1;

        int[] dp = new int[N + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
}


