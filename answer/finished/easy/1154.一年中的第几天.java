import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

/*
 * @lc app=leetcode.cn id=1154 lang=java
 *
 * [1154] 一年中的第几天
 *
 * https://leetcode-cn.com/problems/ordinal-number-of-date/description/
 *
 * algorithms
 * Easy (48.63%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    2.1K
 * Total Submissions: 4.4K
 * Testcase Example:  '"2019-01-09"\r'
 *
 * 给你一个按 YYYY-MM-DD 格式表示日期的字符串 date，请你计算并返回该日期是当年的第几天。
 * 
 * 通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2
 * 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：date = "2019-01-09"
 * 输出：9
 * 
 * 
 * 示例 2：
 * 
 * 输入：date = "2019-02-10"
 * 输出：41
 * 
 * 
 * 示例 3：
 * 
 * 输入：date = "2003-03-01"
 * 输出：60
 * 
 * 
 * 示例 4：
 * 
 * 输入：date = "2004-03-01"
 * 输出：61
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * date.length == 10
 * date[4] == date[7] == '-'，其他的 date[i] 都是数字。
 * date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日。
 * 
 * 
 */

/* Test Case:

"2019-01-09"
"2019-02-10"
"2003-03-01"
"2004-03-01"

*/

/* Method 1: Java API: String.format() + SimpleDateFormat.format() 
class Solution {
    public int dayOfYear(String date) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        Date aim = null;
        try {
            aim = sdf.parse(date);
        } catch(Exception e) {
            e.printStackTrace();
        }
        
        return Integer.parseInt(String.format("%tj", aim));
    }
}
*/

/* Method 2: Java API: LocalDate 
class Solution {
    public int dayOfYear(String date) {
        return LocalDate.parse(date).getDayOfYear();
    }
}
*/

/* Method 2: Java API: LocalDate */
class Solution {

    private static final int[] t1 = {0,31,59,90,120,151,181,212,243,273,304,334};
    private static final int[] t2 = {0,31,60,91,121,152,182,213,244,274,305,335};

    public int dayOfYear(String date) {
        
        int y = Integer.parseInt(date.substring(0, 4));
        int m = Integer.parseInt(date.substring(5, 7));
        int d = Integer.parseInt(date.substring(8, 10));
        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return t2[m - 1] + d;
        return t1[m - 1] + d;
    }
}


