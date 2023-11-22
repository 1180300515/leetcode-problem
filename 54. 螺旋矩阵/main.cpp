# include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() -1 ;
        int up = 0;
        int down = matrix.size() -1 ;
        vector<int> result;
        while(left <= right && up <= down)
        {
            for(int i = left; i <= right; ++i)
            {
                result.emplace_back(matrix[up][i]);
            }
            up++;
            if (up > down)
            {
                break;
            }
            for(int i = up; i<= down; ++i)
            {
                result.emplace_back(matrix[i][right]);
            }
            right--;
            if (left > right)
            {
                break;
            }
            for(int i = right; i >= left; --i)
            {
                result.emplace_back(matrix[down][i]);
            }
            down--;
            for(int i = down; i >= up; --i)
            {
                result.emplace_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};