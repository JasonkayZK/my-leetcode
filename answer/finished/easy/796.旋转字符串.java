/*
 * @lc app=leetcode.cn id=796 lang=java
 *
 * [796] 旋转字符串
 */

/* Test Case:

""
""

*/

/* Method 1: Brute Force

    Time: O(n*n)
    Space: O(1)

class Solution {
    public boolean rotateString(String A, String B) {
        if (A == null) return B == null;
        if (A.length() == 0 && B.length() == 0) return true;
        if (A.length() != B.length()) return false;

        int count = 0;
        while (count < A.length()) {
            if (A.equals(B)) return true;
            A = rotateString(A);
            count++;
        }
        return false;
    }

    private String rotateString(String s) {
        return s.substring(1, s.length()) + s.charAt(0);
    }
}
*/

/* Method 2: Append

    Time: O(n)
    Space: O(1)
*/
class Solution {

    public static boolean rotateString(String A, String B) {
        return A.length() == B.length() && (A+A).contains(B);
    }
    
}



