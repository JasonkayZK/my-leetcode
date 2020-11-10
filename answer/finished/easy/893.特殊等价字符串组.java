/*
 * @lc app=leetcode.cn id=893 lang=java
 *
 * [893] 特殊等价字符串组
 */

// @lc code=start
class Solution {
    public int numSpecialEquivGroups(String[] A) {
        Set<String> set = new HashSet<>();
        for (String str : A) {
            char[] chars = str.toCharArray();
            String odd = "", even = "";
            for (int i = 0; i < chars.length; i++) {
                //如果是奇数位
                if ((i & 1) == 1) {
                    odd += str.charAt(i);
                } else {
                    //如果为偶数位
                    even += str.charAt(i);
                }
            }
            //排序后拼接
            char[] oddArr = odd.toCharArray();
            Arrays.sort(oddArr);
            char[] evenArr = even.toCharArray();
            Arrays.sort(evenArr);
            set.add(new String(oddArr) + new String(evenArr));
        }

        return set.size();
    }
}

// @lc code=end

