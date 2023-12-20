#include <stddef.h>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
        {
            return NULL;
        }
        my(root->right, root);
        my(root->left, root);

        return root;
    }
    void my(Node *des, Node *father)
    {
        if (!des)
        {
            return;
        }

        if (des == father->left && father->right)
        {
            des->next = father->right;
        }
        else
        {
            Node *next = father->next;
            while (next)
            {
                if (next->left)
                {
                    des->next = next->left;
                    break;
                }
                else if (next->right)
                {
                    des->next = next->right;
                    break;
                }
                else
                {
                    next = next->next;
                }
            }
        }
        my(des->right, des);
        my(des->left, des);
    }
};