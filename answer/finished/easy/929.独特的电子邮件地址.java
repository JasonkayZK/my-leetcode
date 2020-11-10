/*
 * @lc app=leetcode.cn id=929 lang=java
 *
 * [929] 独特的电子邮件地址
 */
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();

        for (String email : emails) {
            boolean ignore = false;
            boolean append = false;
            StringBuilder sb = new StringBuilder();
            for (char c: email.toCharArray()) {
                if (append) {
                    sb.append(c);
                } else {
                    if (c == '@') {
                        sb.append(c);
                        append = true;
                        continue;
                    }

                    if (ignore || c == '.') {
                        continue;
                    }

                    if (c == '+') {
                        ignore = true;
                        continue;
                    }

                    sb.append(c);
                }
            }

            set.add(sb.toString());
        }

        return set.size();
    }
}