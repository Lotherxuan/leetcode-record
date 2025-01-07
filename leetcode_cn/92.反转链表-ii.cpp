/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* cur_node = head;
    int count = 1;
    while (count < left - 1) {
      cur_node = cur_node->next;
      count++;
    }
    ListNode* before_left = cur_node;

    count = left;

    ListNode* last_node = cur_node->next;
    cur_node = cur_node->next->next;
    ListNode* next_node = cur_node->next;
    while (count < right) {
      last_node->next = cur_node->next;
    }
  }
};
// @lc code=end
