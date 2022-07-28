//
// Created by kylinkzhang on 2022/4/4.
//

#include "segment_tree.h"

SegmentTree::SegmentTree(int init_size) : tree(vector(init_size, 0)) {}

SegmentTree::SegmentTree() = default;

void SegmentTree::build(int node, int l, int r, const vector<int> &nums) {
  if (l == r) { // the leaf node
    tree[node] = nums[l];
    return;
  }

  int mid = l + (r - l) / 2;
  build(node * 2 + 1, l, mid, nums);
  build(node * 2 + 2, mid + 1, r, nums);

  tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

void SegmentTree::change(int index, int val, int node, int s, int e) {
  if (s == e) {
    tree[node] = val;
    return;
  }
  int m = s + (e - s) / 2;
  if (index <= m) {
    change(index, val, node * 2 + 1, s, m);
  } else {
    change(index, val, node * 2 + 2, m + 1, e);
  }
  tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

int SegmentTree::range(int left, int right, int node, int s, int e) {
  if (left == s && right == e) {
    return tree[node];
  }
  int m = s + (e - s) / 2;
  if (right <= m) {
    return range(left, right, node * 2 + 1, s, m);
  } else if (left > m) {
    return range(left, right, node * 2 + 2, m + 1, e);
  } else {
    return range(left, m, node * 2 + 1, s, m) + range(m + 1, right, node * 2 + 2, m + 1, e);
  }
}
