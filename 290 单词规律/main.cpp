#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> record;
        unordered_map<string, char> record2;
        int count = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ' || i == s.size() - 1)
            {
                string a = "";
                if (i == s.size() - 1)
                {
                    a = s.substr(start, i - start + 1);
                }
                else
                {
                    a = s.substr(start, i - start);
                }
                if (record.count(pattern[count]) == 0 && record2.count(a) == 0)
                {
                    record[pattern[count]] = a;
                    record2[a] = pattern[count];
                }
                else if (record.count(pattern[count]) != 0 && record2.count(a) != 0)
                {
                    if (record[pattern[count]] != a || record2[a] != pattern[count])
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                start = i + 1;
                count++;
            }
        }
        if (count != pattern.size())
        {
            return false;
        }
        return true;
    }
};