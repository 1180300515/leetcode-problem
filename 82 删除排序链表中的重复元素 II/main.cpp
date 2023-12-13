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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *virtual_head = new ListNode(-1, head);
        int cur = head->val;
        ListNode *start = virtual_head;
        ListNode *index = head->next;
        while (index)
        {
            if (index->val == cur)
            {
                start->next = index->next;
            }
            else
            {
                cur = index->val;
                if (start->next != index)
                {
                    start = start->next;
                }
            }
            index = index->next;
        }
        return virtual_head->next;
    }
};