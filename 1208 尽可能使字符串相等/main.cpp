#include <string>

using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int length = s.length();
        int result = 0;
        int sum_old = 0;
        int j_old = 0;
        int j = 0;
        int sum_current = 0;
        for (int i = 0; i < length; ++i)
        {
            if (sum_old != 0)
            {
                sum_current = sum_old - abs(s[i - 1] - t[i - 1]);
                j = j_old;
                sum_old = 0;
                j_old = 0;
            }
            else
            {
                j = i;
                sum_current = abs(s[i] - t[i]);
                sum_old = 0;
                j_old = 0;
            }
            while (sum_current <= maxCost)
            {
                ++j;
                if (j == length)
                {
                    return j - i;
                }
                sum_current += abs(s[j] - t[j]);
            }
            j_old = j - 1;
            sum_old = sum_current - abs(s[j] - t[j]);
            if (result < j - i)
            {
                result = j - i;
            }
            if (result >= length - i)
            {
                break;
            }
        }
        return result;
    }
};