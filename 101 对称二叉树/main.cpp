
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return isornot(root->left, root->right);
    }
    bool isornot(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }
        else if (!left || !right)
        {
            return false;
        }
        else if (left->val != right->val)
        {
            return false;
        }
        return isornot(left->left, right->right) && isornot(left->right, right->left);
    }
};