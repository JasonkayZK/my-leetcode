#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <queue>
#include <sstream>
#include <list>
#include <set>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <ctime>
#include <type_traits>
#include <cstdint>

using namespace std;

class Solution {
 public:

  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> s;

    for (int i = 0; i < nums.size(); ++i) {
      if (s.count(target - nums[i]) > 0) {
        return {s[target - nums[i]], i};
      }
      s[nums[i]] = i;
    }
    return {};
  }

 private:

};

int main() {

  return 0;
}
