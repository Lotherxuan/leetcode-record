/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode* next) : val(x), next(next) {}
// };
class Solution {
  //递归
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !(head->next)) {
      return head;
    }
    ListNode* rec_res = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rec_res;
  }
};
//循环要注意空间复杂度是可以为常数级的
// class Solution {
//  public:
//   ListNode* reverseList(ListNode* head) {
//     ListNode* cur = nullptr;
//     while (head) {
//       ListNode* next = head->next;
//       head->next = cur;
//       cur = head;
//       head = next;
//     }
//     return cur;
//   }
// };

// class Solution {
//  public:
//   ListNode* reverseList(ListNode* head) {
//     if (head == nullptr) {
//       return nullptr;
//     }
//     ListNode* old_node = new ListNode(head->val);
//     head = head->next;
//     if (head == nullptr) {
//       return old_node;
//     }
//     while (head != nullptr) {
//       ListNode* new_node = new ListNode(head->val);
//       new_node->next = old_node;
//       old_node = new_node;
//       head = head->next;
//     }
//     return old_node;
//   }
// };
// @lc code=end
