/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *A_to_B = headA;
    ListNode *B_to_A = headB;
    ListNode *res = nullptr;
    bool A_next = false;
    bool B_next = false;
    while (true) {
      if (A_to_B == B_to_A) {
        res = A_to_B;
        break;
      }
      if (!A_to_B->next && !A_next) {
        A_to_B = headB;
        A_next = true;
      } else {
        A_to_B = A_to_B->next;
      }
      if (!B_to_A->next && !B_next) {
        B_to_A = headA;
        B_next = true;
      } else {
        B_to_A = B_to_A->next;
      }
      if (A_next && B_next && (!A_to_B && !B_to_A)) {
        break;
      }
    }
    return res;
  }
};
// @lc code=end
