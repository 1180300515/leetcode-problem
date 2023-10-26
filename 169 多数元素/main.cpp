#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int tag = nums.at(0);
        int num = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == tag)
            {
                ++num;
            }
            else
            {
                if (num > floor(nums.size() / 2))
                {
                    return tag;
                }
                tag = nums[i];
                num = 1;
            }
        }
        return tag;
    }
};

int main(int argc, char **argv)
{
    vector<int> a = {3, 3, 4};
    Solution so;
    cout << so.majorityElement(a) << endl;
}