/*
 * @lc app=leetcode.cn id=806 lang=java
 *
 * [806] 写字符串需要的行数
 */

/* Test Case:

[10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
"abcdefghijklmnopqrstuvwxyz"
[4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
"bbbcccdddaaa"

*/

/* Method 1: Math

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int pos = 0,row = 0;
        int[] res = new int[2];
        for(char i : S.toCharArray()) {
            if(pos + widths[i-97] <= 100) {
                pos = pos + widths[i - 97];
            } else {
                //如果当前字母写不下了，另起一行
                pos = widths[i - 97];
                row += 1;
            }            
        }
        res[0] = row + 1;
        res[1] = pos;
        return res;
    }
}
// @lc code=end

