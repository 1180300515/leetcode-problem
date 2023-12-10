

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *result;
        result = head;
        if (left == right)
        {
            return head;
        }
        ListNode *last;
        ListNode *cur = head;
        int count = 1;
        while (count != left)
        {
            last = cur;
            cur = cur->next;
            count++;
        }
        ListNode *next = cur->next;
        count++;
        ListNode *origin = next->next;
        while (true)
        {
            next->next = cur;

            cur = next;
            if (count == right)
            {
                if (!last)
                {
                    result = cur;
                }
                break;
            }
            next = origin;
            count++;
            if (!origin)
            {
                break;
            }
            origin = origin->next;
        }
        if (last)
        {
            last->next->next = origin;
            last->next = cur;
        }
        else
        {
            head->next = origin;
        }

        return result;
    }
};