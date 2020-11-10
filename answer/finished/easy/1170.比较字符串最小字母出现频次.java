import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1170 lang=java
 *
 * [1170] 比较字符串最小字母出现频次
 *
 * https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/
 *
 * algorithms
 * Easy (55.68%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    872
 * Total Submissions: 1.6K
 * Testcase Example:  '["cbd"]\n["zaaaz"]'
 *
 * 我们来定义一个函数 f(s)，其中传入参数 s 是一个非空字符串；该函数的功能是统计 s  中（按字典序比较）最小字母的出现频次。
 * 
 * 例如，若 s = "dcce"，那么 f(s) = 2，因为最小的字母是 "c"，它出现了 2 次。
 * 
 * 现在，给你两个字符串数组待查表 queries 和词汇表 words，请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是满足
 * f(queries[i]) < f(W) 的词的数目，W 是词汇表 words 中的词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：queries = ["cbd"], words = ["zaaaz"]
 * 输出：[1]
 * 解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
 * 
 * 
 * 示例 2：
 * 
 * 输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * 输出：[1,2]
 * 解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= queries.length <= 2000
 * 1 <= words.length <= 2000
 * 1 <= queries[i].length, words[i].length <= 10
 * queries[i][j], words[i][j] 都是小写英文字母
 * 
 * 
 */

/* Test Case:

["cbd"]
["zaaaz"]
["bbb","cc"]
["a","aa","aaa","aaaa"]
["bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"]
["aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"]
*/

/* Method 1: Sort + BinarySearch */
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] dict = new int[words.length];
        int[] answer = new int[queries.length];
        
        for (int i = 0; i < dict.length; ++i) dict[i] = findMinCharacterShownTime(words[i]);
        Arrays.sort(dict);

        int len = words.length;
        for (int i = 0; i < queries.length; ++i) {
            answer[i] = len - 1 - binSearch(dict, findMinCharacterShownTime(queries[i]));
        }
        return answer;
    }

    private int findMinCharacterShownTime(String str) {
        char minChar = Character.MAX_VALUE;
        int[] dict = new int[26];
        for(char c : str.toCharArray()) {
            if (c < minChar) minChar = c;
            dict[c - 'a']++;
        }
        return dict[minChar - 'a'];
    }

    private int binSearch(int[] a, int value) {
        int low = 0, high = a.length - 1, mid = 0, n = a.length;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (a[mid] > value) {
                high = mid - 1;
            } else {
                if ((mid == n - 1) || (a[mid + 1] > value)) return mid;
                else low = mid + 1;
            }
        }
        return -1;
    }

}

