#include <unordered_map>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int length = postorder.size();
        for (int i = 0; i < length; ++i)
        {
            record[inorder[i]] = i;
        }
        return my(inorder, postorder, 0, length - 1, 0, length - 1);
    }

    TreeNode *my(vector<int> &inorder, vector<int> &postorder, int left, int right, int inorder_left, int inorder_right)
    {
        // cout << left << right << inorder_left << inorder_right << endl;
        if (left > right)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[right]);
        int index = record[postorder[right]];
        int left_length = index - inorder_left;
        int right_length = inorder_right - index;
        root->left = my(inorder, postorder, left, left + left_length - 1, inorder_left, index - 1);
        root->right = my(inorder, postorder, right - right_length, right - 1, index + 1, inorder_right);
        return root;
    }

private:
    unordered_map<int, int> record;
};