import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1160 lang=java
 *
 * [1160] 拼写单词
 */

/* Test Case:

["cat","bt","hat","tree"]
"atach"
["hello","world","leetcode"]
"welldonehoneyr"

*/

/* Method 1: Array as HashMap 

    Time: O(n + m * x)
    Space: O(1)

    n = len(chars), m = len(words), x = len(words[i])
*/
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] dict = new int[26];

        for (char c : chars.toCharArray()) dict[c - 'a']++;
        int res = 0;
        for (String str : words) {
            int[] curDict = Arrays.copyOf(dict, dict.length);
            boolean finished = true;
            for (char c : str.toCharArray()) {
                curDict[c - 'a']--;
                if (curDict[c - 'a'] < 0) {
                    finished = false;
                    break;
                }
            }
            if (finished) res += str.length();
        }

        return res;
    }
}

