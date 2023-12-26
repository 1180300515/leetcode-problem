#include<vector>
#include<limits.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        inorder(root);
    }

    int next()
    {
        return record[index++];
    }

    bool hasNext()
    {
        if (index >= record.size())
        {
            return false;
        }
        return true;
    }

private:
    vector<int> record;
    int cur = INT_MIN;
    int index = 0;
    void inorder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        record.emplace_back(root->val);
        inorder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */