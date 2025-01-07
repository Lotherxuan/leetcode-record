/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
 public:
  ListNode* reverjseList(ListNode* head) {
    ListNode* cur = nullptr;
    while (head) {
      ListNode* next = head->next;
      head->next = cur;
      cur = head;
      head = next;
    }
    return cur;
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) {
      return head;
    }
    bool take_reverse = false;
    int count = 1;
    ListNode* res = head;
    ListNode* group_head = head;
    ListNode* last_grouphead = nullptr;
    while (head) {
      if (count == k) {
        ListNode* cur = head;
        ListNode* next = head->next;
        cur->next = nullptr;
        reverjseList(group_head);
        if (take_reverse) {
          last_grouphead->next = cur;
        } else {
          res = cur;
          take_reverse = true;
        }
        last_grouphead = group_head;
        group_head = next;
        head = next;
        count = 1;
        continue;
      }
      head = head->next;
      count++;
    }
    last_grouphead->next = group_head;
    return res;
  }
};
// @lc code=end
