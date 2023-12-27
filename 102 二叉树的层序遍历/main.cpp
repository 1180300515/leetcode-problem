#include <vector>
#include <queue>

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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
        {
            return {};
        }
        vector<vector<int>> result;
        queue<TreeNode*> record;
        record.push(root);
        while(!record.empty())
        {
            int size = record.size();
            vector<int> item;
            while(size > 0)
            {
                TreeNode* node = record.front();
                record.pop();
                item.emplace_back(node->val);
                //cout << node->val << endl;
                if (node->left)
                {
                    record.push(node->left);
                }
                if (node->right)
                {
                    record.push(node->right);
                }
                size--;
            }
            result.emplace_back(item);
        }
        return result;
    }
};