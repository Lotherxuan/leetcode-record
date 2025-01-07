/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
}; */
using namespace std;

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL && slow != NULL) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
// @lc code=end
