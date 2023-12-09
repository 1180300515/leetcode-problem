#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return NULL;
        }
        Node* result = new Node(-1);
        Node* cur = result;
        unordered_map<Node*, Node*> record;
        while(head)
        {
            if(record.count(head))
            {
                cur->next = record[head];
            }
            else
            {
                cur->next = new Node(head->val);
                //cout << "next create: " << head->val << endl;
                record[head] = cur->next;
            } 
            cur = cur->next;
            if(head->random)
            {
                if(record.count(head->random))
                {
                    cur->random = record[head->random];
                }
                else
                {
                    cur->random = new Node(head->random->val);
                    //cout << "random create: " << head->random->val << endl;
                    record[head->random] = cur->random;
                }

            }
            head = head->next;
        }
        return result->next;
    }
};