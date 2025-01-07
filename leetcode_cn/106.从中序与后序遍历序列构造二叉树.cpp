/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
  TreeNode* help_func(vector<int>& postorder, vector<int>& inorder,
                      int post_start, int post_end, int in_start, int in_end) {
    if (postorder.empty() && inorder.empty()) {
      return nullptr;
    }
    int mid_value = postorder[post_end];
    int mid_index = find(inorder.begin() + in_start,
                         inorder.begin() + in_end + 1, mid_value) -
                    inorder.begin();
    int left_length = mid_index - in_start;
    int right_length = in_end - mid_index;
    TreeNode* root = new TreeNode(mid_value);
    if (left_length) {
      root->left =
          help_func(postorder, inorder, post_start,
                    post_start + left_length - 1, in_start, mid_index - 1);
    } else {
      root->left = NULL;
    }
    if (right_length) {
      root->right = help_func(postorder, inorder, post_start + left_length,
                              post_end - 1, mid_index + 1, in_end);
    } else {
      root->right = NULL;
    }
    return root;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return help_func(postorder, inorder, 0, postorder.size() - 1, 0,
                     inorder.size() - 1);
  }
};
// @lc code=end
