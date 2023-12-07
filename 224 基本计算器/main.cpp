#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<char> ops;
        int sign = 1;
        int sum = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] == '+')
            {
                continue;
            }
            else if (s[i] == '-')
            {
                ops.push(s[i]);
                sign = -1 * sign;
            }
            else if (s[i] == '(')
            {
                ops.push(s[i]);
            }

            else if (s[i] == ')')
            {
                if (!ops.empty() && ops.top() == '(')
                {
                    ops.pop();
                    if (!ops.empty() && ops.top() == '-')
                    {
                        ops.pop();
                        sign = -1 * sign;
                    }
                }
            }
            else
            {
                int num = 0;
                while (s[i] >= '0')
                {
                    num = num * 10 - '0' + s[i];
                    i++;
                }
                i--;
                sum += num * sign;
                // cout << num * sign << endl;
                if (!ops.empty() && ops.top() == '-')
                {
                    ops.pop();
                    sign = -1 * sign;
                }
            }
        }
        return sum;
    }
};
