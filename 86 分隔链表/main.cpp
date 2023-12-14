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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *virtual_head = new ListNode(0, head);
        ListNode *begin = virtual_head;
        ListNode *cur = head;
        ListNode *last = virtual_head;
        while (cur)
        {
            if (cur->val < x && begin->next != cur)
            {
                last->next = cur->next;
                cur->next = begin->next;
                begin->next = cur;

                cur = last->next;
                begin = begin->next;
            }
            else if (cur->val < x && begin->next == cur)
            {
                begin = begin->next;
                last = cur;
                cur = cur->next;
            }
            else
            {
                last = cur;
                cur = cur->next;
            }
        }
        return virtual_head->next;
    }
};