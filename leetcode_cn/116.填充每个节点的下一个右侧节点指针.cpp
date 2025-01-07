/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  void connec_two(Node* root_left, Node* root_right) {
    if (root_left && root_right) {
      root_left->next = root_right;
      if (root_left->right && root_right->left) {
        connec_two(root_left->left, root_left->right);
        connec_two(root_left->right, root_right->left);
        connec_two(root_right->left, root_right->right);
      }
    }
  }
  Node* connect(Node* root) {
    if (root) {
      connec_two(root->left, root->right);
    }
    return root;
  }
};
// @lc code=end
