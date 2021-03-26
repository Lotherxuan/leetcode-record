/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    if (!root) {
      return res;
    }

    q.push(root);
    q.push(nullptr);
    int last_value = 0;
    while (!q.empty()) {
      TreeNode* front = q.front();

      if (front) {
        last_value = front->val;
        if (front->left) {
          q.push(front->left);
        }
        if (front->right) {
          q.push(front->right);
        }
        q.pop();
      } else {
        res.push_back(last_value);
        q.pop();
        if (!q.empty()) {
          q.push(nullptr);
        } else {
          break;
        }
      }
    }

    return res;
  }
};
// @lc code=end
