#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        string tag = "";
        for (int i = s.size() - 1; i >= 0; --i)
        {
            cout << s[i] << endl;
            if (s[i] == ' ')
            {
                cout << tag << endl;
                if (tag != "")
                {
                    result.append(tag);
                    result.append(" ");
                    tag = "";
                }
            }
            else
            {
                tag.insert(0, s, i, 1);
            }
        }
        if (tag != "")
        {
            result.append(tag);
            result.append(" ");
            tag = "";
        }
        if (result.back() == ' ')
        {
            result.pop_back();
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution so;
    string result = so.reverseWords("the sky is blue");
    cout << result << endl;
    // string a = "aba";
    // a.insert(2, 1, 'b');
    // cout << a << endl;

    return 0;
}