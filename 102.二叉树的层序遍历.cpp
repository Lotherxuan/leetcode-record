/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
  //该实现时间渐进复杂度是没问题的，但实现方法不好，运行时间和使用内存表现都不理想，可以使用空指针作为定界符，只使用一个queue
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    deque<TreeNode *> q1;
    deque<TreeNode *> q2;
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    q1.push_front(root);
    vector<int> scan;
    while (!q1.empty() || !q2.empty()) {
      if (q1.empty()) {
        q1.assign(q2.begin(), q2.end());
        q2.clear();
      }
      while (!q1.empty()) {
        TreeNode *head = q1.front();
        if (head->left) {
          q2.push_back(head->left);
        }
        if (head->right) {
          q2.push_back(head->right);
        }
        scan.push_back(head->val);
        q1.pop_front();
      }
      res.push_back(scan);
      scan.clear();
    }
    return res;
  }
};
// @lc code=end
