#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int result = 0;
        while(end < s.size())
        {
            int j = judge(s.substr(start,end -start), s[end]);
            if (j != INT_MAX)
            {
                start = start + j + 1;
            }
            result = result > end -start + 1? result : end - start + 1;
            end++;
        }
        return result;
    }
    int judge(string s , char d)
    {
        for(int i = 0 ; i  < s.size() ; ++i)
        {
            if (d == s[i])
            {
                return i;
            }
        }
        return INT_MAX;
    }
};