//
// Created by JasonkayZK on 2022/3/26.
//

#ifndef MY_LEETCODE_TREE_H
#define MY_LEETCODE_TREE_H

#include "../utils/utils.h"

// Definition for a binary tree node.
class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //MY_LEETCODE_TREE_H
