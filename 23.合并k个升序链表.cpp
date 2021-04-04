/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
#include <queue>
#include <vector>
using namespace std;
// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode* next) : val(x), next(next) {}
// }

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }
    auto cmp = [](ListNode* l0, ListNode* l1) { return l0->val > l1->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
    // for (auto& list : lists) {
    //   ListNode* cur = list;
    //   while (cur != nullptr) {
    //     q.push(cur);
    //     cur = cur->next;
    //   }
    // }
    for (auto i = lists.begin(); i < lists.end(); i++) {
      if (!(*i)) {
        continue;
      }
      ListNode* cur = (*i);
      while (cur != nullptr) {
        q.push(cur);
        cur = cur->next;
      }
    }
    if (q.empty()) {
      return nullptr;
    }
    ListNode* top_node = q.top();
    ListNode* pre_node = top_node;
    ListNode* res_node = top_node;
    while (!q.empty()) {
      q.pop();
      top_node = q.top();
      pre_node->next = q.top();
      pre_node = q.top();
    }
    pre_node->next = nullptr;
    return res_node;
  }
};
// @lc code=end
