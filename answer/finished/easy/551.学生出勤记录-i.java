/*
 * @lc app=leetcode.cn id=551 lang=java
 *
 * [551] 学生出勤记录 I
 *
 * https://leetcode-cn.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (48.66%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 13.6K
 * Testcase Example:  '"PPALLP"'
 *
 * 给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：
 * 
 * 
 * 'A' : Absent，缺勤
 * 'L' : Late，迟到
 * 'P' : Present，到场
 * 
 * 
 * 如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
 * 
 * 你需要根据这个学生的出勤记录判断他是否会被奖赏。
 * 
 * 示例 1:
 * 
 * 输入: "PPALLP"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 输入: "PPALLL"
 * 输出: False
 * 
 * 
 */
class Solution {
    public boolean checkRecord(String s) {
        char[] chs = s.toCharArray();
        int a = 0, l = 0;
        for (int i = 0; i < chs.length;) {
            if (chs[i] == 'A') a++;
            if (a > 1) return false;
            if (chs[i] == 'L') {
                l++;
                while (i+1 < chs.length && chs[i+1] == 'L') {
                    l++;
                    i++;
                }
                if (l > 2) return false;
            }
            l = 0;
            i++;
        }
        return true;
    }
}

