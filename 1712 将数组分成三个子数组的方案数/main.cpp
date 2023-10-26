#include <vector>

using namespace std;

class Solution
{
public:
    int waysToSplit(vector<int> &nums)
    {
        int MOD = 1000000007;
        int length = nums.size();
        int total = 0;
        int result = 0;
        for (int i = 0; i < length; ++i)
        {
            total += nums[i];
        }
        int left = 0;
        for (int i = 1; i < length - 1; ++i)
        {
            left += nums[i - 1];
            if (left >= total - left)
            {
                continue;
            }
            int j_left = i + 1;
            int mid = nums[j_left - 1];
            while (j_left != length && left > mid)
            {
                ++j_left;
                mid += nums[j_left - 1];
            }
            if (j_left == length)
            {
                continue;
            }
            int j_right = length - 1;
            int right = nums[j_right];
            while (j_right >= j_left && right < total - right - left)
            {
                --j_right;
                right += nums[j_right];
            }

            result += j_right - j_left + 1;
        }
        return result % MOD;
    }
};