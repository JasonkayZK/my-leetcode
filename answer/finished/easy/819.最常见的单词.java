/*
 * @lc app=leetcode.cn id=819 lang=java
 *
 * [819] 最常见的单词
 */

/* Test Case:

"Bob hit a ball, the hit BALL flew far after it was hit."
["hit"]

*/

/* Method 1: Traverse: Two Pointer

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        //数组转Set
        Set<String> set = new HashSet<>(Arrays.asList(banned));
        set.add("");
        paragraph += ".";
        //结果单词
        String res = " ";
        //最大单词出现次数
        int times = 0;
        //记录单词出现次数的map
        Map<String, Integer> map = new HashMap<>();
        //i,k为双指针
        int i = 0;
        for (int k = 0; k < paragraph.length(); k++) {
            char c = paragraph.charAt(k);
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                continue;
            } else {
                //利用双指针截取出一个单词
                String word = paragraph.substring(i, k);
                //统一将单词转为小写
                word = word.toLowerCase();
                if (!set.contains(word)) {
                    map.put(word, map.getOrDefault(word, 0) + 1);
                    //最大值的获取
                    if (map.get(word) > times) {
                        res = word;
                        times = map.get(word);
                    }
                }
                i = k + 1;
            }
        }
        return res;
    }
}


