//
// Created by kylinkzhang on 2022/4/4.
//

#ifndef MY_LEETCODE_SEGMENT_TREE_H
#define MY_LEETCODE_SEGMENT_TREE_H

#include "../utils/utils.h"

class SegmentTree {
 private:
  vector<int> tree;

 public:

  SegmentTree();

  explicit SegmentTree(int init_size);

  void build(int node, int l, int r, const vector<int> &nums);

  void change(int index, int val, int node, int s, int e);

  int range(int left, int right, int node, int s, int e);

};

#endif //MY_LEETCODE_SEGMENT_TREE_H
