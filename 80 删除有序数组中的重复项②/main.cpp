#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 3)
        {
            return length;
        }
        int slow = 1;
        int fast = 1;
        int tag = 1;
        while (fast < length)
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
                tag = 1;
            }
            else if (nums[fast] == nums[fast - 1] && tag != 2)
            {
                nums[slow] = nums[fast];
                ++slow;
                ++tag;
            }
            ++fast;
        }
        return slow;
    }
};