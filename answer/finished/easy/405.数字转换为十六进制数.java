/*
 * @lc app=leetcode.cn id=405 lang=java
 *
 * [405] 数字转换为十六进制数
 */

/* Test Case: 

26
-1
0
3214
321
122
-1325

*/

/* Method 1: Bit Operation 

    Time: O(log(n))
    Space: O(1)

*/

class Solution {

    private char[] HEXDict = new char[] {
        '0', '1', '2', '3', '4', '5',
        '6', '7', '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };

    public String toHex(int num) {
        if (num == 0) return "0";

        int temp = 0;
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            temp = num & 0x0000000f;
            sb.append(HEXDict[temp]);
            num >>>= 4;
        }

        return sb.reverse().toString();
    }
}

