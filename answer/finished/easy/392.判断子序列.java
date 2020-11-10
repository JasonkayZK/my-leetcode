/*
 * @lc app=leetcode.cn id=392 lang=java
 *
 * [392] 判断子序列
 */
class Solution {
    public boolean isSubsequence(String s, String t) {
        char[] chars = s.toCharArray();
        int index = -1;
        for (char temp:chars) {
            index = t.indexOf(temp, index + 1);
            if (index == -1) return false;
        }
        return true;
    }
}

