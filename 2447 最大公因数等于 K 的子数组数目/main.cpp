#include <vector>

using namespace std;

class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int length = nums.size();
        int result = 0;
        for (int i = 0; i < length; ++i)
        {
            if (nums[i] % k != 0)
            {
                continue;
            }
            if (nums[i] == k)
            {
                ++result;
            }
            int temp = nums[i];
            for (int j = i + 1; j < length; ++j)
            {
                temp = gcd(temp, nums[j]);
                if (temp != k)
                {
                    continue;
                }
                ++result;
            }
        }

        return result;
    }
    int gcd(int a, int b)
    {
        int temp = 0;
        if (a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        int r = a % b;
        while (r != 0)
        {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }
};