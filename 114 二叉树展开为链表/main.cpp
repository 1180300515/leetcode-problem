

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
    void flatten(TreeNode *root)
    {
        my(root);
    }
    TreeNode *my(TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }
        TreeNode *right = root->right;
        root->right = my(root->left);
        root->left = nullptr;
        TreeNode *next = root;
        while (next->right)
        {
            next = next->right;
        }
        next->right = my(right);
        return root;
    }
};