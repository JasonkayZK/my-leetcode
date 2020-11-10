/*
 * @lc app=leetcode.cn id=686 lang=java
 *
 * [686] 重复叠加字符串匹配
 */


/* Method 1: Brute Force */
class Solution {
    public int repeatedStringMatch(String A, String B) {
        int count = 1;
        StringBuilder sb = new StringBuilder(A);
        while(sb.length() < 2 * A.length() + B.length()) {
            if(sb.indexOf(B) == -1) {
                 sb.append(A);
                 count++;   
            }
            else return count; 
        }
      return -1;
    }
}

