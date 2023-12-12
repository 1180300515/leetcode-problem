

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *slow = head;
        ListNode *fast = head;
        int count = 0;
        while (fast)
        {
            if (count == n + 1)
            {
                slow = slow->next;
            }
            else
            {
                count++;
            }
            fast = fast->next;
        }
        if (slow == head && count != n + 1)
        {
            return head->next;
        }
        else
        {
            slow->next = slow->next->next;
        }
        return head;
    }
};