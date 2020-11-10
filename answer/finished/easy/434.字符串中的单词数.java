/*
 * @lc app=leetcode.cn id=434 lang=java
 *
 * [434] 字符串中的单词数
 */

/* Test Case:

"Hello, my name is John"
""
"    dasf  fadsf"
"asdf asdfqw, | fasdf"
" adsf, fsadfwef/ ewqfweff qwefqwefqw    "

*/


/* Method 1: Java API: String 
class Solution {
    public int countSegments(String s) {
        if (s == null || s.length() == 0) {return 0;}

        s = s.trim();
        String[] arr = s.split(" ");
        int res = 0;
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i].trim().length() != 0) res++;
        }
        return res;
    }
}
*/

/* Method 2: Char Manipulation 

    Time: O(n)
    Space: O(n)
*/
class Solution {
    public int countSegments(String s) {
        int res = 0;
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] != ' ') res++;
            while (i < arr.length && arr[i] != ' ') ++i;
        }
        return res;
    }
}

