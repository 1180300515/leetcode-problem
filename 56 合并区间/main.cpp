#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &x, vector<int> &y) -> bool
             {
            if(x[0] == y[0])
            {
                return x[1] < y[1];
            }
            return x[0] < y[0]; });
        vector<vector<int>> result;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (auto item : intervals)
        {
            if (right >= item[0])
            {
                right = right > item[1] ? right : item[1];
            }
            else
            {
                result.push_back({left, right});
                left = item[0];
                right = item[1];
            }
        }
        result.push_back({left, right});
        return result;
    }
};