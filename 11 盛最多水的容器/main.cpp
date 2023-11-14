#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        int tag = 0;
        int min = 0;
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                min = height[left];
                tag = left;
            }
            else
            {
                min = height[right];
                tag = right;
            }
            result = result > (right - left) * min ? result : (right - left) * min;
            if (tag == left)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }
};