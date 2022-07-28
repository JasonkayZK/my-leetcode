//
// Created by kylinkzhang on 2022/4/29.
//

#ifndef MY_LEETCODE_UNION_FIND_H
#define MY_LEETCODE_UNION_FIND_H

#include "../utils/utils.h"

#endif //MY_LEETCODE_UNION_FIND_H

template<class T>
class UnionFind {

 private:
  unordered_map<T, T> father;

  int strongly_connected_component_cnt = 0;

  const T NOT_FOUND_FLAG;

 public:
  explicit UnionFind(T notFoundFlag) : NOT_FOUND_FLAG(notFoundFlag) {}

  [[nodiscard]]
  int get_strongly_connected_component_cnt() const {
    return strongly_connected_component_cnt;
  }

  void add(T x) {
    if (father.count(x) == 0) {
      father[x] = NOT_FOUND_FLAG;
      ++strongly_connected_component_cnt;
    }
  }

  void merge(T x, T y) {
    T root_x = find(x);
    T root_y = find(y);

    if (root_x != root_y) {
      father[root_x] = root_y;
      --strongly_connected_component_cnt;
    }
  }

  bool is_connect(T x, T y) {
    return find(x) == find(y);
  }

  T find(T x) {
    T cur = x;

    while (father[cur] != NOT_FOUND_FLAG) {
      cur = father[cur];
    }

    while (x != cur) { // path compression
      int old_father = father[x];
      father[x] = cur;
      x = old_father;
    }
    return cur;
  }
};
