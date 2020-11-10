import java.util.Random;

/*
 * @lc app=leetcode.cn id=5307 lang=java
 *
 * [5307] 将整数转换为两个无零整数的和
 */

/* Test Case:

2
9

*/

// @lc code=start
/**
 * Method 1: Random
 * 
 * Time: O(log(n))
 * Space: O(1)
 * 

class Solution {

    Random random = new Random();

    public int[] getNoZeroIntegers(int n) {
        int left, right;
        while (true) {
            left = random.nextInt(n);
            right = n - left;
            if ((Integer.toString(left) + Integer.toString(right)).indexOf("0", 0) < 0) {
                return new int[] { left, right };
            }
        }
    }
}
 */

/* Method 2: Brute Force

    Time: O(nlng(n))
    Space: O(1)
*/
class Solution {
    
    public int[] getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (!containsZero(i) && !containsZero(n - i))
                return new int[]{i, n - i};
        }
        return new int[2];
    }

    private boolean containsZero(int n) {
        while (n > 0) {
            if (n % 10 == 0)
                return true;
            n /= 10;
        }
        return false;
    }

}
// @lc code=end

