/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };
#include <deque>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    deque<TreeNode *> q_left_to_right;
    deque<TreeNode *> q_right_to_left;
    q_left_to_right.push_back(root);
    vector<int> level;
    while (!q_left_to_right.empty() || !q_right_to_left.empty()) {
      if (!q_left_to_right.empty()) {
        while (!q_left_to_right.empty()) {
          TreeNode *back = q_left_to_right.back();
          level.push_back(back->val);
          if (back->left) {
            q_right_to_left.push_back(back->left);
          }
          if (back->right) {
            q_right_to_left.push_back(back->right);
          }
          q_left_to_right.pop_back();
        }
        res.push_back(level);
        level.resize(0);
      }
      if (!q_right_to_left.empty()) {
        while (!q_right_to_left.empty()) {
          TreeNode *back = q_right_to_left.back();
          level.push_back(back->val);
          if (back->right) {
            q_left_to_right.push_back(back->right);
          }
          if (back->left) {
            q_left_to_right.push_back(back->left);
          }
          q_right_to_left.pop_back();
        }
        res.push_back(level);
        level.resize(0);
      }
    }
    return res;
  }
};
// @lc code=end
