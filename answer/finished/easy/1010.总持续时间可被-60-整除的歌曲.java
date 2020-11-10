/*
 * @lc app=leetcode.cn id=1010 lang=java
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

/* Test Case:

[30,20,150,100,40]
[60,60,60]

*/


/* Method 1: Brute Force[TLE]

    Time: O(n^2)
    Space: O(1)

class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int res = 0;
        for (int i = 0; i < time.length; ++i) {
            for (int j = i + 1; j < time.length; ++j) {
                if ((time[i] + time[j]) % 60 == 0) res++;
            }
        }
        return res;
    }
}
*/

/* Method 2: Array as HashMap

    Time: > O(n)
    Space: < O(n)
*/
// @lc code=start
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] map = new int[60];

        for (int i = 0; i < time.length; ++i) {
            time[i] = time[i] % 60;
        }

        int res = 0;
        for (int i = 0; i < time.length; ++i) {
            int rest = (60 - time[i]) % 60;

            res += map[rest];

            map[time[i]]++;
        }
        return res;
    }
}

// @lc code=end

