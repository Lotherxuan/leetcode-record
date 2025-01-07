/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
/* struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int a = 0;
        ListNode *headnode = new ListNode((l1->val + l2->val + a) % 10);
        headnode->next = NULL;
        a = (l1->val + l2->val + a) / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode *newnode = headnode;

        while (l1 != NULL && l2 != NULL)
        {
            newnode->next = new ListNode((l1->val + l2->val + a) % 10);
            newnode = newnode->next;
            newnode->next = NULL;
            a = (l1->val + l2->val + a) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL)
        {
            while (l2 != NULL)
            {
                newnode->next = new ListNode((l2->val + a) % 10);
                newnode = newnode->next;
                newnode->next = NULL;
                a = (l2->val + a) / 10;
                l2 = l2->next;
            }
        }
        if (l2 == NULL)
        {
            while (l1 != NULL)
            {
                newnode->next = new ListNode((l1->val + a) % 10);
                newnode = newnode->next;
                newnode->next = NULL;
                a = (l1->val + a) / 10;
                l1 = l1->next;
            }
        }
        if (a)
        {
            newnode->next = new ListNode(a);
            newnode = newnode->next;
            newnode->next = NULL;
        }
        return headnode;
    }
};
// @lc code=end
