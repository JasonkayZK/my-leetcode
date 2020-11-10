import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=728 lang=java
 *
 * [728] 自除数
 */

/* Test Case:

1
22
3
3134

*/

/* Method 1: Brute Force 

    Time: O(right - left + 1)
    Space: O(1)
*/
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> res = new ArrayList<>(right - left + 1);
        for (int i = left; i <= right; ++i) {
            if (isSelfDividingNumber(i)) res.add(i);
        }
        return res;
    }

    private boolean isSelfDividingNumber(int num) {
        if (num == 0) return false;
        int temp = num;
        while (temp != 0) {
            int mod = temp % 10;
            if (mod == 0 || num % mod != 0) return false;
            temp /= 10;
        }
        return true;
    }
}

