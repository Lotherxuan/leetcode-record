/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <vector>
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    wrapper(root, res);
    return res;
  }

  void wrapper(TreeNode* root, vector<int>& res) {
    if (root) {
      res.push_back(root->val);
      wrapper(root->left, res);
      wrapper(root->right, res);
    }
  }
};
// @lc code=end
