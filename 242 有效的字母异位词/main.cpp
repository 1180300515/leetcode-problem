#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> record;
        for (int i = 0; i < s.size(); ++i)
        {
            record[s[i]]++;
        }
        for (int i = 0; i < t.size(); ++i)
        {
            if (record.count(t[i]) == 0)
            {
                return false;
            }
            else
            {
                record[t[i]]--;
                if (record[t[i]] == 0)
                {
                    record.erase(t[i]);
                }
            }
        }
        return true;
    }
};