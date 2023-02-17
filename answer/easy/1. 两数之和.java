package answer.easy;

import java.util.HashMap;

class Solution1 {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        HashMap<Integer, Integer> m = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int aim = target - nums[i];
            if (m.containsKey(aim)) {
                return new int[]{i, m.get(aim)};
            } else {
                m.put(nums[i], i);
            }
        }

        return new int[]{};
    }
}