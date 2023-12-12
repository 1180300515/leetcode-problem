

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *virtual_head = new ListNode(-1, head);
        auto test = head;
        int count = 0;
        int num = 0;
        while (test)
        {
            count++;
            if (count == k)
            {
                num++;
                count = 0;
            }
            test = test->next;
        }
        if (num == 0)
        {
            return head;
        }
        ListNode *left = virtual_head;
        ListNode *last = head;
        ListNode *cur = head->next;
        while (true)
        {
            int count = 2;
            while (count <= k)
            {
                last->next = cur->next;
                cur->next = left->next;
                left->next = cur;

                cur = last->next;
                count++;
            }
            num--;
            if (num == 0)
            {
                break;
            }
            left = last;
            last = cur;
            cur = cur->next;
        }
        return virtual_head->next;
    }
};