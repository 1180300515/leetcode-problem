#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> answer = vector<int>(length, 0);
        for (int i = 0; i < length; ++i)
        {
            if (i == 0)
            {
                answer[i] = 1;
            }
            else
            {
                answer[i] = answer[i - 1] * nums[i - 1];
            }
        }
        for (auto iter : answer)
        {
            cout << iter << endl;
        }
        int multi = 1;
        for (int i = length - 1; i >= 0; --i)
        {
            if (i == length - 1)
            {
                answer[i] = answer[i] * 1;
            }
            else
            {
                multi *= nums[i + 1];
                answer[i] = answer[i] * multi;
            }
        }
        return answer;
    }
};