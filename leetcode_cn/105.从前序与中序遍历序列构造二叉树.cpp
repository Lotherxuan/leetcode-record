/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

/* #include "TreeNode.h" */
using namespace std;
class Solution {
 public:
  TreeNode* help_func(vector<int>& preorder, vector<int>& inorder,
                      int pre_start, int pre_end, int in_start, int in_end) {
    if (preorder.empty() && inorder.empty()) {
      return nullptr;
    }
    int mid_value = preorder[pre_start];
    int mid_index = find(inorder.begin() + in_start,
                         inorder.begin() + in_end + 1, mid_value) -
                    inorder.begin();
    int left_length = mid_index - in_start;
    int right_length = in_end - mid_index;
    TreeNode* root = new TreeNode(mid_value);
    if (left_length) {
      root->left = help_func(preorder, inorder, pre_start + 1,
                             pre_start + left_length, in_start, mid_index - 1);
    } else {
      root->left = NULL;
    }
    if (right_length) {
      root->right = help_func(preorder, inorder, pre_start + left_length + 1,
                              pre_end, mid_index + 1, in_end);
    } else {
      root->right = NULL;
    }
    return root;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return help_func(preorder, inorder, 0, preorder.size() - 1, 0,
                     inorder.size() - 1);
  }
};
// @lc code=end
