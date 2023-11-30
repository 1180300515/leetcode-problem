#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }
        vector<string> result;
        int left = 0;
        int right = 0;
        while (left < nums.size())
        {
            if (right < nums.size() && (left == right || nums[right] == nums[right - 1] || nums[right] == nums[right - 1] + 1))
            {
                right++;
            }
            else
            {
                string item = to_string(nums[left]);
                if (left != right - 1)
                {
                    item = item + "->" + to_string(nums[right - 1]);
                }
                result.emplace_back(item);
                left = right;
                right = left;
            }
        }
        return result;
    }
};