#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        map<int, string> dict = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}};
        string result = "";
        for (auto iter = dict.rbegin(); iter != dict.rend(); iter++)
        {
            cout << num << "  " << iter->first << endl;
            int a = num / iter->first;
            if (a != 0 && iter->second.size() == 2)
            {
                num -= iter->first;
                result.append(iter->second);
            }
            else if (a != 0)
            {
                num -= iter->first * a;
                for (auto i = 1; i <= a; ++i)
                {
                    result.append(iter->second);
                }
            }
        }
        return result;
    }
};