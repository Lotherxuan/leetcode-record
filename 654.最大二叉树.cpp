/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <vector>
using namespace std;

/* #include "TreeNode.h" */
class Solution {
 public:
  TreeNode* help_func(vector<int>& nums, int start, int end) {
    int max_index = start;
    int max_value = numeric_limits<int>::min();
    int cur_index = start;
    while (cur_index <= end) {
      if (nums[cur_index] >= max_value) {
        max_index = cur_index;
        max_value = nums[cur_index];
      }
      cur_index++;
    }
    TreeNode* root = new TreeNode(max_value);
    if (max_index - 1 >= start) {
      root->left = help_func(nums, start, max_index - 1);
    } else {
      root->left = NULL;
    }
    if (end >= max_index + 1) {
      root->right = help_func(nums, max_index + 1, end);
    } else {
      root->right = NULL;
    }
    return root;
  }
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return help_func(nums, 0, nums.size() - 1);
  }
};
// @lc code=end
