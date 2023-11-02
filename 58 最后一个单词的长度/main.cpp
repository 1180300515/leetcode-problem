#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        bool begin = false;
        int length = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (!begin && s[i] == ' ')
            {
                continue;
            }
            else if (begin && s[i] == ' ')
            {
                break;
            }
            else
            {
                begin = true;
                length++;
            }
        }
        return length;
    }
};