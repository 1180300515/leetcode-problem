#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> record;
        while (head != NULL)
        {
            if (record.count(head) != 0)
            {
                return true;
            }
            record.insert(head);
            head = head->next;
        }
        return false;
    }
};