#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jump_count = 0;
        int index_max = 0;
        int old_index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (index_max >= nums.size() - 1)
            {
                ++jump_count;
                break;
            }
            if (i <= old_index)
            {
                index_max = index_max > i + nums[i] ? index_max : i + nums[i];
            }
            else
            {
                ++jump_count;
                old_index = index_max;
                index_max = index_max > i + nums[i] ? index_max : i + nums[i];
            }
        }
        return jump_count;
    }
};