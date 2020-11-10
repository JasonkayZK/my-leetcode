import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=401 lang=java
 *
 * [401] 二进制手表
 *
 * https://leetcode-cn.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (48.88%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 10.9K
 * Testcase Example:  '0'
 *
 * 二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。
 * 
 * 每个 LED 代表一个 0 或 1，最低位在右侧。
 * 
 * 
 * 
 * 例如，上面的二进制手表读取 “3:25”。
 * 
 * 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
 * 
 * 案例:
 * 
 * 
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16",
 * "0:32"]
 * 
 * 
 * 
 * 注意事项:
 * 
 * 
 * 输出的顺序没有要求。
 * 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
 * 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
 * 
 * 
 */

/* Test Case:

1
3
4
5
9

*/

/* Method 1: Java API: Integer.bitCount() 
class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (Integer.bitCount(i) + Integer.bitCount(j) == num) {
                    res.add(String.format("%d:%02d", i, j));
                }
            }
        }
        return res;
    }
}
*/

/* Method 2: Dict */
public class Solution {
    String[][] hour = {{"0"},  // hours contains 0 1's
               {"1", "2", "4", "8"},   // hours contains 1 1's
               {"3", "5", "6", "9", "10"},  // hours contains 2 1's
               {"7", "11"}};  // hours contains 3 1's
    String[][] minute = {{"00"},  // mins contains 0 1's
                     {"01", "02", "04", "08", "16", "32"},  // mins contains 1 1's
                     {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"},  // mins contains 2 1's
                     {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"},  // mins contains 3 1's
                     {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"},  // mins contains 4 1's
                     {"31", "47", "55", "59"}};  // mins contains 5 1's
    public List<String> readBinaryWatch(int n) {
        List<String> ret = new ArrayList();
            // loop from 0 to 3 which is the max number of bits can be set in hours (4 bits)
        for (int i = 0; i <= 3 && i <= n; i++) {
                        // this if condition is to make sure the index from minutes array would be valid
            if (n - i <= 5) {
                            // if we have i 1's in hours, then we need n - i 1's in minutes, that's why the arrays were created by grouping the number of 1's bits
                for (String str1 : hour[i]) {
                    for (String str2 : minute[n - i]) {
                        ret.add(str1 + ":" + str2);
                    }
                }
            }
        }
        return ret;     
    }
}

