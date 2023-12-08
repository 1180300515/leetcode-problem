

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *result = nullptr;
        ListNode *cur = nullptr;
        int value;
        while (list1 || list2)
        {
            if (list1 && list2 && list1->val > list2->val)
            {
                value = list2->val;
                list2 = list2 ? list2->next : list2;
            }
            else if (list1 && list2 && list1->val <= list2->val)
            {
                value = list1->val;
                list1 = list1 ? list1->next : list1;
            }
            else if (list1)
            {
                value = list1->val;
                list1 = list1->next;
            }
            else
            {
                value = list2->val;
                list2 = list2->next;
            }
            // cout << value << endl;
            if (!result)
            {
                result = cur = new ListNode(value);
            }
            else
            {
                cur->next = new ListNode(value);
                cur = cur->next;
            }
        }
        return result;
    }
};