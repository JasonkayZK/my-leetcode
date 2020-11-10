import java.util.Map;
import java.util.TreeMap;

/*
 * @lc app=leetcode.cn id=1122 lang=java
 *
 * [1122] 数组的相对排序
 */


/* Test Case:

[2,3,1,3,2,4,6,7,9,2,19]
[2,1,4,3,9,6]

*/

/* Method 1: HashMap 

    Time: O(nlog(n) + m) 
    Space: O(n) n = len(arr1), m = len(arr2)
*/
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> map = new TreeMap<>();
        int[] res = new int[arr1.length];

        for (int n : arr1) map.put(n, map.getOrDefault(n, 0) + 1);

        int cur = 0;
        for (int n : arr2) {
            int index = map.get(n);
            while (index-- > 0) res[cur++] = n;
            map.remove(n);
        }

        if (!map.isEmpty()) {
            for (int key : map.keySet()) {
                int index = map.get(key);
                while (index-- > 0) res[cur++] = key;
            }
        }

        return res;
    }
}

