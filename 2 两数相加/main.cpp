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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        ListNode *cur = result;
        ListNode *old = result;
        int tag = 0;
        int num1, num2;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1)
            {
                num1 = l1->val;
            }
            else
            {
                num1 = 0;
            }
            if (l2)
            {
                num2 = l2->val;
            }
            else
            {
                num2 = 0;
            }
            if (num1 + num2 + tag >= 10)
            {
                cur->val = num1 + num2 + tag - 10;
                tag = 1;
            }
            else
            {
                cur->val = num1 + num2 + tag;
                tag = 0;
            }
            ListNode *item = new ListNode();
            cur->next = item;
            old = cur;
            cur = item;
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (tag == 1)
        {
            cur->val = 1;
        }
        else
        {
            old->next = nullptr;
            delete cur;
        }
        return result;
    }
};