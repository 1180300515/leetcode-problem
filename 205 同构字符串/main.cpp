#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> record;
        unordered_set<char> t_record;
        for (int i = 0; i < t.size(); ++i)
        {
            if (record.count(s[i]) == 0)
            {
                if (t_record.count(t[i]) == 1)
                {
                    return false;
                }
                record[s[i]] = t[i];
                t_record.emplace(t[i]);
            }
            else
            {
                if (record[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};