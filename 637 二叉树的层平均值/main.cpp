#include <unordered_map>
#include <vector>
#include <numeric>

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        dfs(root, 0);
        for (int i = 0 ; i < record.size(); ++i)
        {
            result.emplace_back( (double)accumulate(record[i].begin(), record[i].end(), 0.0) / record[i].size());
        }
        return result;
    }

    void dfs(TreeNode* root , int deep)
    {
        if (!root)
        {
            return;
        }
        record[deep].emplace_back(root->val);
        dfs(root->left, deep+1);
        dfs(root->right, deep+1);
    }
private:
    unordered_map<int, vector<int>> record;
};