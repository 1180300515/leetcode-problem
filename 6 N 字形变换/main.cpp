#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int hash = numRows + numRows - 2;
        int num = 0;
        int length = s.size();
        string result = "";
        if (length <= numRows || numRows == 1)
        {
            return s;
        }
        while(num < numRows)
        {
            int i = num;
            while(i < length)
            {
                result.push_back(s[i]);
                int k = i + (numRows - num - 1)*2;
                if (k < length && num != 0 && num != hash / 2 )
                {
                    result.push_back(s[k]);
                }
                i += hash;
            }
            ++num;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution so;
    string result = so.convert("PAYPALISHIRING",4);
    cout << result << endl;
    // string a = "aba";
    // a.insert(2, 1, 'b');
    // cout << a << endl;

    return 0;
}