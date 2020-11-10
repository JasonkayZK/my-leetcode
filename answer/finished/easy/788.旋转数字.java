/*
 * @lc app=leetcode.cn id=788 lang=java
 *
 * [788] 旋转数字
 */


/* Method 1: Brute force

    Time: O(n)
    Space: O(1)
*/

// @lc code=start
class Solution {
    public int rotatedDigits(int N) {
        int ans = 0;
        
        for (int i = 1;i <= N;i++) {
            if (judge(i)) {
                ans++;
            }
        }
        
        return ans;
    }
    
    private boolean judge(int num) {
        String rule = "0182569";
        boolean ok = false;
        
        while (num != 0) {
            int m = num % 10;
            
            if (rule.indexOf((char) (m + '0')) < 0) {
                return false;
            }
            
            if (m == 2 || m == 5 || m == 6 || m == 9) {
                ok = true;
            }
            
            num /= 10;
        }
        
        return ok;
    }
}

// @lc code=end

