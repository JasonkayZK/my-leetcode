package answer.easy;

import java.util.ArrayList;
import java.util.List;

class Solution118 {
    public List<List<Integer>> generate(int numRows) {
        ArrayList<List<Integer>> res = new ArrayList<>(numRows);

        for (int i = 1; i <= numRows; i++) {
            List<Integer> curLevel = new ArrayList<>(i);
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) {
                    curLevel.add(j, 1);
                } else {
                    List<Integer> prevLevel = res.get(i - 2);
                    curLevel.add(j, prevLevel.get(j - 1) + prevLevel.get(j));
                }
            }
            res.add(curLevel);
        }
        return res;
    }
}

