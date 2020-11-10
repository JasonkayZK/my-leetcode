import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=349 lang=java
 *
 * [349] 两个数组的交集
 */

/* Test Case:

[1,2,2,1]
[2,2]
[4,9,5]
[9,4,9,8,4]

*/

/* Method 1: Java API: Two Set

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1 == null || nums1.length == 0 || nums2 == null || nums2.length == 0) {return new int[0];}
        
        Set<Integer> set1 = new HashSet<>();
        for (int num : nums1) {
            set1.add(num);
        }
        Set<Integer> set2 = new HashSet<>();
        for (int num : nums2) {
            set2.add(num);
        }

        set1.retainAll(set2);

        Object[] result = set1.toArray();

        int[] res = new int[result.length];
        for (int i = 0; i < res.length; ++i) {
            res[i] = (int)result[i];
        }
        return res;
    }
}
 */

/* Method 2: One Set */

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> res = new ArrayList<>();
        Set<Integer> set = new HashSet<>();

        for (int num : nums1) set.add(num);
        for (int num : nums2) {
            if (set.contains(num)) {
                res.add(num);
                set.remove(num);
            }
        }

        int[] arr = new int[res.size()];
        for (int i = 0; i < arr.length; ++i) arr[i] = res.get(i);
        return arr;
    }
}

