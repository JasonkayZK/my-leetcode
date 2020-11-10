import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=506 lang=java
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (50.96%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 8.3K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        if (nums == null || nums.length == 0) return new String[0];
        int len = nums.length;
        int[] temp = Arrays.copyOf(nums, len);
        Arrays.sort(temp);

        Map<Integer, String> rank = new HashMap<>(len);
        for (int i = len - 1; i >= 0; --i) {
            if (i == len - 1) rank.put(temp[i], "Gold Medal");
            else if (i == len - 2) rank.put(temp[i], "Silver Medal");
            else if (i == len - 3) rank.put(temp[i], "Bronze Medal");
            else rank.put(temp[i], String.valueOf(len - i));
        }

        String[] res = new String[len];
        for (int i = 0; i < len; ++i) res[i] = rank.get(nums[i]);
        return res;
    }
}

