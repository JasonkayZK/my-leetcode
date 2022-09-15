#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(students.begin(), students.end());
    sort(seats.begin(), seats.end());
    int res = 0;
    int n = int(students.size());
    for (int i = 0; i < n; ++i){
      res += abs(students[i] - seats[i]);
    }
    return res;
  }

 private:

};

int main() {


  return 0;
}
