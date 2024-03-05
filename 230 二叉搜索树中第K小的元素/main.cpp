#include <vector>

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

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root);
        return record[k - 1];
    }
    void dfs(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left);
        record.emplace_back(root->val);
        dfs(root->right);
    }

private:
    vector<int> record;
};