/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

#include <vector>
#include <stack>
/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; */
using namespace std;

/* 递归
class Solution
{

public:
    void inorder(vector<int> &result, TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            inorder(result, root->left);
            result.push_back(root->val);
            inorder(result, root->right);
            return;
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorder(result, root);
        return result;
    }
}; */

//迭代
class Solution
{

public:
    void inorder(vector<int> &res, TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        stack<TreeNode *> node_stack;
        TreeNode *cur_node = root;

        while (cur_node || !node_stack.empty())
        {
            while (cur_node)
            {
                node_stack.push(cur_node);
                cur_node = cur_node->left;
            }
            cur_node = node_stack.top();
            res.push_back(cur_node->val);
            node_stack.pop();
            cur_node = cur_node->right;
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder(res, root);
        return res;
    }
};

// @lc code=end
