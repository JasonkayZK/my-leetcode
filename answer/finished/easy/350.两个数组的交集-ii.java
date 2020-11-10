import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=350 lang=java
 *
 * [350] 两个数组的交集 II
 */

/* Test Case:

[1,2,2,1]
[2,2]
[4,9,5]
[9,4,9,8,4]

*/

/* Method 1: HashMap 

    Time: O(mlog(n)) 
    Space: O(m + n) n = len(nums1), m = len(nums2)


class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> res = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>(nums1.length);

        for (int num : nums1) map.put(num, map.getOrDefault(num, 0) + 1);
        for (int num : nums2) {
            if (map.containsKey(num)) {
                if (map.get(num) == 1) map.remove(num);
                else map.put(num, map.get(num) - 1);
                res.add(num);
            }
        }

        int[] arr = new int[res.size()];
        for (int i = 0; i < arr.length; ++i) arr[i] = res.get(i);
        return arr;
    }
}
*/

/* Method 2: Sort */
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1 == null || nums1.length == 0 || nums2 == null || nums2.length == 0) {return new int[0];}

        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int i = 0, j = 0, k = 0;
        while(i<nums1.length && j<nums2.length){
            if(nums1[i]<nums2[j] )
                i++;
            else if(nums2[j]<nums1[i])
                j++;
            else if(nums1[i]==nums2[j]){
                nums1[k++]=nums1[i];
                i++;            
                j++;
            }
        }
        return Arrays.copyOf(nums1, k);
    }
}



