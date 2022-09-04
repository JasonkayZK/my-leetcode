#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int mostBooked(int n, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) {
      return a[0] < b[0];
    });

    vector<int> cnt(n);
    priority_queue<book_meeting, vector<book_meeting>, cmp> pq;
    for (int i = 0; i < n; ++i) {
      pq.emplace(book_meeting(0, i, 0));
    }

    int res = 0, cur_cnt = 0;
    for (const auto &item : meetings) {

      auto cur_room = pq.top();
      pq.pop();
      pq.emplace(book_meeting())

      if (cnt[idx] > cur_cnt) {
        cur_cnt = cnt[idx];
        res = idx;
      }
    }

    return res;
  }

 private:

  struct book_meeting {

    book_meeting(int i, int i_1, int i_2, int i_3) {
      start_time = i;
      end_time = i_1;
      room_idx = i_2;
      time_offset = i_3;
    }

    int start_time;
    int end_time;
    int room_idx;
    int time_offset;
  };

  struct cmp {
    bool operator()(const book_meeting &x, const book_meeting &y) {
      if (x.start_time + x.time_offset == y.start_time + y.time_offset) {
        return x.end_time < y.end_time;
      }
      return x.start_time + x.time_offset < y.start_time + y.time_offset;
    }
  };

};

int main() {

  return 0;
}
