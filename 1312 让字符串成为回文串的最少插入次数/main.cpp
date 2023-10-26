#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        int length = s.length();
        int i = 0;
        int j = length - 1;
        int result = 0;
        while (i != j && i - j != 1)
        {
            if (s[i] == s[j])
            {
                ++i;
                --j;
            }
            else
            {
                if (j == s.length() - 1)
                {
                    s.push_back(s[i]);
                }
                else
                {
                    s.insert(j + 1, 1, s[i]);
                }
                ++result;
                ++i;
            }
        }
        cout << s << endl;
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution so;
    int result = so.minInsertions("zjveiiwvc");
    cout << result << endl;
    // string a = "aba";
    // a.insert(2, 1, 'b');
    // cout << a << endl;

    return 0;
}