#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> record;
        for (auto item : s)
        {
            switch (item)
            {
            case ')':
                if (!record.empty() && record.top() == '(')
                {
                    record.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (!record.empty() && record.top() == '[')
                {
                    record.pop();
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if (!record.empty() && record.top() == '{')
                {
                    record.pop();
                }
                else
                {
                    return false;
                }
                break;
            default:
                record.push(item);
            }
        }
        if (record.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};