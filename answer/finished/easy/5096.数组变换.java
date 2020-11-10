import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=5096 lang=java
 *
 * [5096] 数组变换
 */

/* Test Case:

[6,2,3,4]
[1,6,3,4,3,5]
[2,1,2,1,1,2,2,1]


*/

/* Method 1: Brute Force

    Time: (n * max(change))
    Space: (n)
*/
// @lc code=start
class Solution {
    public List<Integer> transformArray(int[] arr) {
        if (arr == null || arr.length == 0) return new ArrayList<>();

        boolean changed = true;
        while (changed) {
            changed = false;
            int[] temp = Arrays.copyOf(arr, arr.length);
            for (int i = 1; i < arr.length - 1; ++i) {
                if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                    temp[i]++;
                    changed = true;
                } else if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                    temp[i]--;
                    changed = true;                
                }
            }
            arr = temp;
        }

        List<Integer> res = new ArrayList<>(arr.length);
        for (int n : arr) {
            res.add(n);
        }
        return res;
    }
}
// @lc code=end

