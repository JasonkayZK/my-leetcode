import java.util.PriorityQueue;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=748 lang=java
 *
 * [748] 最短完整词
 */


/* Test Case:

"1s3 PSt"
["step", "steps", "stripe", "stepple"]
"1s3 456"
["looks", "pest", "stew", "show"]
"B687015"
["born","give","would","nice","in","understand","blue","force","have","that"]

*/

/* Method 1: Brute Force:

    Time: O(n)
    Space: < O(n)
*/
// @lc code=start
class Solution {
    
    private int[] dict;

    public String shortestCompletingWord(String licensePlate, String[] words) {
        Queue<String> res = new PriorityQueue<>((x, y) -> {
            if (x.length() != y.length()) return x.length() - y.length();
            return 1;
        });
        licensePlate = licensePlate.toLowerCase();

        dict = new int[26];
        for (char c : licensePlate.toCharArray()) {
            if (Character.isAlphabetic(c)) dict[c - 'a']++;
        }

        for (String s : words) {
            if (checkString(s)) res.offer(s);
        }
        return res.peek();
    }

    private boolean checkString(String s) {
        int[] temp = new int[26];
        for (char c : s.toCharArray()) {
            temp[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (temp[i] < dict[i]) return false;
        }
        return true;
    }

}
// @lc code=end

