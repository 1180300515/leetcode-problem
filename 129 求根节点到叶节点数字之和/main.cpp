
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
    int sumNumbers(TreeNode *root)
    {
        return my(root, 0);
    }
    int my(TreeNode *root, int num)
    {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            return num * 10 + root->val;
        }
        return my(root->left, num * 10 + root->val) + my(root->right, num * 10 + root->val);
    }
};