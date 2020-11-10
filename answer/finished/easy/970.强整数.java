import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=970 lang=java
 *
 * [970] 强整数
 */

/* Test Case:

1
1
100
1
2
100
2
1
100
2
3
10
3
5
15
1
2
1000000

*/

/* Method 1: Set 

    Time: O(n ^ 2log(n))
    Space: O(bound)

class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> set = new HashSet<>(bound);

        boolean isOneX = false, isOneY = false;
    
        for (int xi = 1; xi < bound && !isOneX; xi *= x, isOneX = x == 1) {
            isOneY = false;
            for (int yj = 1; yj + xi <= bound && !isOneY; yj *= y, isOneY = y == 1) {
                set.add(xi + yj);
            }
        }
        List<Integer> res = new ArrayList<>(set.size());
        for (int n : set) res.add(n);
        return res;
    }
}
*/

/* Method 2: Brute Force: Math: Log 

    Time: O(log(n) ^ 2)
    Space: O(log(n) ^ 2)
*/
class Solution { 
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> seen = new HashSet();
        for (int i = 0; i < 20 && Math.pow(x, i) <= bound; ++i)
            for (int j = 0; j < 20 && Math.pow(y, j) <= bound; ++j) {
                int v = (int) Math.pow(x, i) + (int) Math.pow(y, j);
                if (v <= bound)
                    seen.add(v);
            }

        return new ArrayList(seen);
    }
}
