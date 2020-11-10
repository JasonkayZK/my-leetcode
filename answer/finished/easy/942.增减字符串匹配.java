/*
 * @lc app=leetcode.cn id=942 lang=java
 *
 * [942] 增减字符串匹配
 *
 * https://leetcode-cn.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (69.83%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 11.1K
 * Testcase Example:  '"IDID"'
 *
 * 给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。
 * 
 * 返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：
 * 
 * 
 * 如果 S[i] == "I"，那么 A[i] < A[i+1]
 * 如果 S[i] == "D"，那么 A[i] > A[i+1]
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输出："IDID"
 * 输出：[0,4,1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 输出："III"
 * 输出：[0,1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 输出："DDI"
 * 输出：[3,2,0,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 1000
 * S 只包含字符 "I" 或 "D"。
 * 
 * 
 */

/* Test Case :

"D"
"I"
"DD"
"II"
"DI"
"ID"
"IDID"
"III"
"DDI"

*/

/* Method 1: Two Pointer 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int[] diStringMatch(String S) {
        int l = 0, r = S.length();
        int[] res = new int[S.length() + 1];
        for (int i = 0; i < S.length(); ++i) {
            if ('D' == S.charAt(i)) {
                res[i] = r--;
            }
            else {
                res[i] = l++;
            }
        }
        res[S.length()] = l;
        return res;
    }
}

