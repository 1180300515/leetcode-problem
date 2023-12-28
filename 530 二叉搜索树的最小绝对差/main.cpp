#include <limits.h>
#include <vector>
#include <algorithm>

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
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int min = INT_MAX;
        sort(record.begin(),record.end());
        for(int i = 0; i < record.size() -1 ; ++i)
        {
            if (min > record[i + 1] - record[i] && record[i + 1] - record[i] != 0)
            {
                min = record[i + 1] - record[i];
            }
        }
        return min;
    }
    
    void dfs(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        record.emplace_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
private:
    vector<int> record;
};