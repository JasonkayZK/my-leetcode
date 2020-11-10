/*
 * @lc app=leetcode.cn id=387 lang=java
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (40.07%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    39.2K
 * Total Submissions: 97.9K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */

/* Test Case:

""
"a"
"abba"
"abcaace"
"asdfas"
"leetcode"
"loveleetcode"

*/

/* Method 1: Two-time Iteration + ArrayHashMap

    Time: O(2n)
    Space: O(1)

class Solution {
    public int firstUniqChar(String s) {
        if (s == null || s.length() == 0) {return -1;}

        char[] arr = s.toCharArray();
        int[] dict = new int[26];

        for (char c : arr) dict[c - 'a']++;
        for (int i = 0; i < arr.length; ++i) {
            if (dict[arr[i] - 'a'] == 1) return i;
        }
        return -1;
    }
}
*/

/* Method 2: HashMap + List

    Time: O(nlog(n))
    Space: O(n)
*/
class Solution {
    public int firstUniqChar(String s) {
        if (s == null || s.length() == 0) {return -1;}

        char[] arr = s.toCharArray();
        Map<Character, Integer> charPos = new HashMap<>(arr.length);
        List<Integer> uniquePos = new ArrayList<>(arr.length);

        for (int i = 0; i < arr.length; ++i) {
            if (charPos.containsKey(arr[i])) uniquePos.remove(Integer.valueOf(charPos.get(arr[i])));
            else {
                charPos.put(arr[i], i);
                uniquePos.add(i);
            }
        }
        return uniquePos.isEmpty() ? -1 : uniquePos.get(0);
    }
}

