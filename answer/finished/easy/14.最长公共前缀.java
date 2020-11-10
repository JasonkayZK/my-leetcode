/*
 * @lc app=leetcode.cn id=14 lang=java
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.47%)
 * Likes:    660
 * Dislikes: 0
 * Total Accepted:    109.8K
 * Total Submissions: 318.6K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

 /*
    Test Case: 
    ["c","c"]
    ["cat", "catzk"]
 */

class Solution {

    /*  按照字符index单个比较
    
        public String longestCommonPrefix(String[] strs) {
            if (strs.length <= 0) { return "";}
            if (strs.length == 1) { return strs[0];}
    
            int index = 0;
            int minLength = minLength(strs);
            
    
            while (index < minLength) {
                char curChar = strs[0].charAt(index);
                for (int i = 0; i < strs.length; i++) {
                    if (strs[i].charAt(index) != curChar) {
                        return index == 0 ? "" : strs[0].substring(0, index);
                    }
                }
                index++;
            }
            return index == 0 ? "" : strs[0].substring(0, index);
        }
    
        private int minLength(String[] strs) {
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < strs.length; i++) {
                min = Math.min(min, strs[i].length());
            }
            return min;
        }
    */
    
    // Method 2: [Best]
    /*  找出最短的string: shortest -> 每次从后向前截断 shortest -> 在其他串中寻找; */
    
        public String longestCommonPrefix(String[] strs) {
            if (strs == null || strs.length < 1) {return "";}
            if (strs.length == 1) {return strs[0];}
    
            // 寻找最短
            int shortestIndex = 0;
            int len = strs[0].length();
            for (int i = 1; i < strs.length; i++) {
                int curLen = strs[i].length();
                if (curLen < len) {
                    len = curLen;
                    shortestIndex = i;
                }
            }
            
            String shortest = strs[shortestIndex];
            for (int i = 0; i < strs.length; i++) {
                while (strs[i].indexOf(shortest) != 0) {
                    shortest = shortest.substring(0, shortest.length() - 1);
                }
            }
            return shortest;
        }
    
    }
    