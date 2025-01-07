/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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

//#include "TreeNode.h"
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
      return root;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (root != NULL) {
      invertTree(root->right);
    };
    if (root != NULL) {
      invertTree(root->left);
    };
    return root;
  }
};
// @lc code=end
