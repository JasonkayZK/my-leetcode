/*
 * @lc app=leetcode.cn id=299 lang=java
 *
 * [299] 猜数字游戏
 */


/* Test Case:

"1807"
"7810"
"1123"
"0111"

*/

/* Method 1: Array as HashMap

    Time: O(n + 10);
    Space: O(20)
*/

// @lc code=start
class Solution {
    public String getHint(String secret, String guess) {
        int aCount = 0;     // 公牛数
        int bCount = 0;     // 母牛数
        int[] mapS = new int[10];
        int[] mapG = new int[10];

        for (int i = 0; i < secret.length(); i++) {
            char temp = secret.charAt(i);
            if (temp == guess.charAt(i))
                aCount++;
            else {
                mapS[temp - '0']++;
                mapG[guess.charAt(i) - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            bCount += Math.min(mapG[i], mapS[i]);
        }
        return aCount + "A" + bCount + "B";
    }
}
// @lc code=end

