/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
#include <string>

/* #include "TreeNode.h" */
using namespace std;
class Codec {
 public:
  // Encodes a tree to a single string.
  void serialize_implete(TreeNode* root, string& s) {
    char sep = ',';
    char null_ptr = '#';
    if (root) {
      s.push_back(root->val + '0');
      s.push_back(sep);
      serialize_implete(root->left, s);
      serialize_implete(root->right, s);

    } else {
      s.push_back(null_ptr);
      s.push_back(sep);
    }
  }
  string serialize(TreeNode* root) {
    string res = "";
    serialize_implete(root, res);
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize_implete(string& data) {
    if (data.empty()) {
      return NULL;
    }
    if (data[0] == '#') {
      return NULL;
    }
    TreeNode* root = new TreeNode(data[0] - '0');
    data = data.substr(2, data.size() - 1);
    root->left = deserialize_implete(data);
    root->right = deserialize_implete(data);
    return root;
  }
  TreeNode* deserialize(string data) { return deserialize_implete(data); }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
