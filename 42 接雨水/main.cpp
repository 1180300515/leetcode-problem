#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int count = 0;
        int left = 0;
        int right = 1;
        while (true)
        {
            while (height[left] <= height[left + 1])
            {
                ++left;
                if (left == height.size() - 1)
                {
                    return count;
                }
            }
            while (true)
            {
                if (right == height.size() -1)
                {
                    break;
                }
                if (left < right && height[right - 1] < height[right] && height[right] >= height[right + 1])
                {
                    break;
                }
                ++right;
            }
            cout << left << "   " << right << endl;
            int deep = height[left] > height[right] ? height[right] : height[left];
            for (int i = left + 1; i < right; ++i)
            {
                count += deep - height[i];
            }
            left = right;
            if (left == height.size() - 1)
            {
                break;
            }
        }
        return count;
    }
};
