import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

/*
 * @lc app=leetcode.cn id=1029 lang=java
 *
 * [1029] 两地调度
 *
 * https://leetcode-cn.com/problems/two-city-scheduling/description/
 *
 * algorithms
 * Easy (54.10%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 5.4K
 * Testcase Example:  '[[10,20],[30,200],[400,50],[30,20]]'
 *
 * 公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。
 * 
 * 返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[[10,20],[30,200],[400,50],[30,20]]
 * 输出：110
 * 解释：
 * 第一个人去 A 市，费用为 10。
 * 第二个人去 A 市，费用为 30。
 * 第三个人去 B 市，费用为 50。
 * 第四个人去 B 市，费用为 20。
 * 
 * 最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= costs.length <= 100
 * costs.length 为偶数
 * 1 <= costs[i][0], costs[i][1] <= 1000
 * 
 * 
 */

/* Test Case: 

[[10,20],[30,200],[400,50],[30,20]]

*/

/* Method 1: Sort + Greedy

    Time: O(nlog(n))
    Space: O(1)

class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Comparator<int[]> comp = new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Math.abs(b[0] - b[1]) - Math.abs(a[0] - a[1]);
            }
        };

        Arrays.sort(costs, comp);
        int lenA = 0, lenB = 0, len = costs.length;
        int cost = 0;
        for (int[] a : costs) {
            if (a[0] > a[1]) {
                if (lenB < len / 2) {
                    lenB++;
                    cost += a[1];
                } else {
                    lenA++;
                    cost += a[0];
                }
            } else {
                if (lenA < len / 2) {
                    lenA++;
                    cost += a[0];
                } else {
                    lenB++;
                    cost += a[1];
                }
            }
        }
        return cost;
    }
}
*/

/* Method 1: Sort + Greedy [Better]

    Time: O(nlog(n))
    Space: O(1)
*/
class Solution {
    public int twoCitySchedCost(int[][] costs) {
      Arrays.sort(costs, new Comparator<int[]>() {
          @Override
          public int compare(int[] o1, int[] o2) {
              return o1[0] - o1[1] - (o2[0] - o2[1]);
          }
      });

      int total = 0;
      int n = costs.length / 2;
      // To optimize the company expenses,
      // send the first n persons to the city A
      // and the others to the city B
      for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
      return total;
    }
}

