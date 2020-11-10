import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=720 lang=java
 *
 * [720] 词典中最长的单词
 */


/* Test Case:

["w","wo","wor","worl", "world"]
["a", "banana", "app", "appl", "ap", "apply", "apple"]
["ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"]

*/

/* Method 1: Sort and Search 

    Time:  > O(nlng(n))
    Space: O(n)

class Solution {
    public String longestWord(String[] words) {
        Set<String> set = new HashSet<>();
        Arrays.sort(words, (str1, str2) -> str1.compareTo(str2));

        String res = null;

        for (String str : words) {
            if (str.length() == 1) {
                set.add(str);
                if (res == null) {
                    res = str;
                }
            } else {
                if (set.contains(str.substring(0, str.length() - 1))) {
                    set.add(str);
                    if (str.length() > res.length()) {
                        res = str;
                    }
                }
            }
        }

        return res;
    }
}
*/

/* Method 2: Optimized */
class Solution {
    public String longestWord(String[] words) {
        if(words.length==1){//先判断特殊用例
            if(words[0].length()==1){
                return words[0];
            }
            else{
                return "";
            }
        }

        Arrays.sort(words);//排序
        int len = 0;

        for(int i=0; i<words.length; i++){
            len = Math.max(len,words[i].length());//获取最长字符串长度
        }
        
        for(int i=len; i>=1; i--){//用最长长度开始扫描
            int pos = 0;
            for(int j=0; j<words.length; j++){
                if(words[j].length()==i){//如果当前字符串长度与最外层循环长度相等
                    pos = j;
                    int temp = i;
                    for(int k=j-1; k>=0; k--){
                        if(words[j].substring(0,temp-1).equals(words[k])){//每次判断减少一个字母是否吻合
                            temp--;
                        }
                    }
                    if(temp==1){//最后剩一个字母
                        return words[j];
                    }
                }
            }
        }
        return "";
    }
}
