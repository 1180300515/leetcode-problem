#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> record;
        for(auto iter: tokens)
        {
            if (iter == "+")
            {
                auto first = record.top();
                record.pop();
                auto second = record.top();
                record.pop();
                auto result = first + second;
                record.push(result);
            }
            else if(iter == "-")
            {
                auto first = record.top();
                record.pop();
                auto second = record.top();
                record.pop();
                auto result = second - first;
                record.push(result);
            }
            else if (iter == "*" )
            {
                auto first = record.top();
                record.pop();
                auto second = record.top();
                record.pop();
                auto result = second * first;
                record.push(result);
            }
            else if(iter == "/")
            {
                auto first = record.top();
                record.pop();
                auto second = record.top();
                record.pop();
                int result = second / first;
                record.push(result);
            }
            else
            {
                auto result = stoi(iter);
                record.push(result);
            }
        }
        return record.top();
    }
};