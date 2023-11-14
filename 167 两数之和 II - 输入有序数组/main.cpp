#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = 0;
        while (left < numbers.size() - 1)
        {
            right = left + 1;
            while (target > numbers[left] + numbers[right])
            {
                if (right == numbers.size() - 1)
                {
                    break;
                }
                right++;
            }
            if (target != numbers[left] + numbers[right])
            {
                while (numbers[left] == numbers[left + 1])
                {
                    left++;
                }
                left++;
            }
            else
            {
                break;
            }
        }
        vector<int> result = {left + 1, right + 1};
        return result;
    }
};