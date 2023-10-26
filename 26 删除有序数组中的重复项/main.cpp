#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int length = nums.size();
        int result = length;
        int pre = nums[0];
        for (int i = 1; i < length; ++i)
        {
            if (pre == nums[i])
            {
                nums[i] = nums.back() + 1;
                --result;
            }
            else
            {
                pre = nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        return result;
    }
};