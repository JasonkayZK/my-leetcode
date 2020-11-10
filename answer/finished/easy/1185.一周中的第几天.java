import java.util.Calendar;

/*
 * @lc app=leetcode.cn id=1185 lang=java
 *
 * [1185] 一周中的第几天
 */

/* Test Case:

31
8
2019
18
7
1999
15
8
1993


*/

/* Method 1: Java Date API */
class Solution {

    private static final String[] map = new String[] {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    public String dayOfTheWeek(int day, int month, int year) {
        Calendar cal = Calendar.getInstance();
        cal.set(Calendar.YEAR, year);
        cal.set(Calendar.MONTH, month - 1);
        cal.set(Calendar.DATE, day);
        return map[cal.get(Calendar.DAY_OF_WEEK) - 1];
    }
}

