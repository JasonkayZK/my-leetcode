package answer.easy;

class Solution70 {
    public int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return n;

        int x = 1, y = 2;
        for (int i = 3; i <= n; i++) {
            int temp = y;
            y += x;
            x = temp;
        }
        return y;
    }
}