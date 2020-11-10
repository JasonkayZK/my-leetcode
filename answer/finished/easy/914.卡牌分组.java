import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=914 lang=java
 *
 * [914] 卡牌分组
 *
 * https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
 *
 * algorithms
 * Easy (31.30%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 16.4K
 * Testcase Example:  '[1,2,3,4,4,3,2,1]'
 *
 * 给定一副牌，每张牌上都写着一个整数。
 * 
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 * 
 * 
 * 每组都有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 * 
 * 
 * 仅当你可选的 X >= 2 时返回 true。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4,4,3,2,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,1,1,2,2,2,3,3]
 * 输出：false
 * 解释：没有满足要求的分组。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1]
 * 输出：false
 * 解释：没有满足要求的分组。
 * 
 * 
 * 示例 4：
 * 
 * 输入：[1,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]
 * 
 * 
 * 示例 5：
 * 
 * 输入：[1,1,2,2,2,2]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[2,2]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= deck.length <= 10000
 * 0 <= deck[i] < 10000
 * 
 * 
 * 
 * 
 */

/* Test Case

[1,2,3,4,4,3,2,1]
[1,1,1,2,2,2,3,3]
[1]
[1,1]
[1,1,2,2,2,2]

*/

/* Method 1: TreeMap-SortByValue + GCD 

    Time: O(nlog(n))
    Space: O(n)
*/

class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer> ();
        for (int n : deck) map.put(n, map.getOrDefault(n, 0) + 1);

        List<Integer> list = new ArrayList<>(map.values());
        Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });

        int last = 0;
        for (int key : list) {
            if (last == 0) last = key;
            last = findgcd(last, key);
            if (last == 1) return false;
        }
        return true;
    }

    private int findgcd(int x, int y) {
        return y == 0 ? x : findgcd(y, x % y);
    }
}

