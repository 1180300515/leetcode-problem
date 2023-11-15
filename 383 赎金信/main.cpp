#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> record = vector<int>(26, 0);
        for (int i = 0; i < magazine.size(); ++i)
        {
            record[(int)magazine[i] - 97]++;
        }
        for (int i = 0; i < ransomNote.size(); ++i)
        {
            record[(int)ransomNote[i] - 97]--;
            if (record[(int)ransomNote[i] - 97] < 0)
            {
                return false;
            }
        }
        return true;
    }
};