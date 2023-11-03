#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int length = strs[0].size();
        bool terminate = false;
        int i = 0;
        for (i = 0; i < length; ++i)
        {
            for (auto iter : strs)
            {
                if (i >= iter.size())
                {
                    terminate = true;
                    break;
                }
                if (iter[i] != strs[0][i])
                {
                    terminate = true;
                    break;
                }
            }
            if (terminate)
            {
                break;
            }
        }
        if (i == 0 )
        {
            return "";
        }
        else
        {
            return strs[0].substr(0,i);
        }
    }
};