#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        int sum = nums[0];
        int result = 0;
        while (true)
        {
            if (sum < target)
            {
                r++;
                if (r == nums.size())
                {
                    break;
                }
                sum += nums[r];
            }
            else
            {
                if (result == 0)
                {
                    result = r - l + 1;
                }
                else
                {
                    result = result > r - l + 1 ? r - l + 1 : result;
                }
                l++;
                if (l == nums.size())
                {
                    break;
                }
                if (l > r)
                {
                    r = l;
                    sum = nums[l];
                }
                else
                {
                    sum -= nums[l - 1];
                }
            }
            // cout << l << " " << r << " " << sum << endl;
        }
        return result;
    }
};