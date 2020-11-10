import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

/*
 * @lc app=leetcode.cn id=811 lang=java
 *
 * [811] 子域名访问计数
 */


/* Test Case:

["9001 discuss.leetcode.com"]
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]

*/

/* Method 1: Brute Force */
 class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();

        for (String s : cpdomains) {
            String[] strs = s.split(" ");
            int cnt = Integer.parseInt(strs[0]);

            String[] webs = strs[1].split("[.]");
            StringBuilder sb = new StringBuilder();
            for(int i = webs.length - 1; i >= 0; --i) {
                if (sb.length() == 0) sb.append(webs[i]);
                else sb.insert(0, webs[i] + ".");
                
                map.put(sb.toString(), map.getOrDefault(sb.toString(), 0) + cnt);
            }
        }


        List<String> res = new ArrayList<>();
        for (Entry<String, Integer> entry : map.entrySet()) {
            res.add(entry.getValue() + " " + entry.getKey());
        }
        return res;
    }
}
// @lc code=end

