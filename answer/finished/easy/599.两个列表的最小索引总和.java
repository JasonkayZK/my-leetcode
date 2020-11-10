import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=599 lang=java
 *
 * [599] 两个列表的最小索引总和
 */

/* Test Case:

["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
["Shogun", "KFC", "Burger King", "KFC2"]
["KFC", "Shogun", "Burger King"]

*/

/* Method 1: HashMap

    Time: O(nlog(m))
    Space: O(m)
*/
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        if (list1.length > list2.length) {
            String[] swap = list1;
            list1 = list2;
            list2 = swap;
        }
         
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < list1.length; ++i) {
            map.put(list1[i], i);
        }

        int min = Integer.MAX_VALUE;
        List<String> res = new ArrayList<>(list1.length + 1);

        for (int i = 0; i < list2.length; ++i) {
            if (map.containsKey(list2[i])) {
                int curIndex = map.get(list2[i]);
                if (curIndex + i < min) {
                    min = curIndex + i;
                    res.clear();
                    res.add(list2[i]);
                } else if (curIndex + i == min) {
                    res.add(list2[i]);
                }
            } 
        }
        return res.toArray(new String[res.size()]);
    }
}

