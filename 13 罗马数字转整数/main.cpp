#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> record;
        record['I'] = 1;
        record['V'] = 5;
        record['X'] = 10;
        record['L'] = 50;
        record['C'] = 100;
        record['D'] = 500;
        record['M'] = 1000;
        int sum = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (i + 1 < s.length() && record[s[i]] < record[s[i + 1]])
            {
                sum -= record[s[i]];
            }
            else
            {
                sum += record[s[i]];
            }
        }
        return sum;
    }
};