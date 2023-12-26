#include <vector>
#include <stddef.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> record_p;
        vector<TreeNode *> record_q;
        my(root, p, record_p);
        my(root, q, record_q);
        // cout << record_p.size() << endl;
        // cout << record_q.size() << endl;
        for (auto iter : record_p)
        {
            // cout << "p : " << iter->val << endl;
            for (auto item : record_q)
            {
                if (iter == item)
                {
                    return iter;
                }
            }
        }
        return NULL;
    }

private:
    bool my(TreeNode *root, TreeNode *des, vector<TreeNode *> &record)
    {
        if (!root)
        {
            return false;
        }
        if (root == des)
        {
            record.emplace_back(des);
            return true;
        }
        if (my(root->left, des, record) || my(root->right, des, record))
        {
            record.emplace_back(root);
            return true;
        }
        return false;
    }
};