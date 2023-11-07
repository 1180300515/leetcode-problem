#include <string>
#include <ctype.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (true)
        {
            if (i >= j)
            {
                return true;
            }
            while (!isalnum(s[i]))
            {
                ++i;
                if (i == s.size() - 1)
                {
                    return true;
                }
            }
            while (!isalnum(s[j]))
            {
                --j;
            }
            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            ++i;
            --j;
        }
    }
};