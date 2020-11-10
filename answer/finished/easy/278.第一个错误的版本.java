/*
 * @lc app=leetcode.cn id=278 lang=java
 *
 * [278] 第一个错误的版本
 */
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

/* Test Case:

5
4
10
4
3
3
1
1

*/

/* Method 1: Binary Search */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        if (n <= 0) throw new RuntimeException("n must higher than 0!");
        if (isBadVersion(1)) {return 1;}
        return findVersion(2, n);
    }

    private int findVersion(int start, int end) {
        if (start == end) {return start;}
        int mid = (end - start) / 2 + start;
        int result = 0;
        boolean curVersion = isBadVersion(mid);
        if (!curVersion) {
            result = findVersion(mid + 1, end);
        } else {
            if (!isBadVersion(mid - 1)) result = mid;
            else result = findVersion(start, mid - 1);
        }
        return result;
    }

}

