#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int length = nums.size();
        int index = 0;
        vector<int> record = vector<int>(nums.size(), 0);

        return jump(nums, 0, record);
    }
    bool jump(vector<int> &nums, int index, vector<int> &record)
    {
        if (nums[index] >= nums.size() - 1 - index)
        {
            record[index] = 2;
            return true;
        }
        else if (index != nums.size() - 1 && nums[index] == 0)
        {
            record[index] = 1;
            return false;
        }
        else
        {
            bool result = false;
            for (int i = 1; i <= nums[index]; ++i)
            {
                if (record[index + i] != 0)
                {
                    result |= record[index + i] == 1 ? false : true;
                }
                else
                {
                    result |= jump(nums, index + i, record);
                }
                if (result)
                {
                    break;
                }
            }
            return result;
        }
    }
};