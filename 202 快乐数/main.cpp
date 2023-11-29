#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> record;
        record.insert(n);
        int new_n = compute(n);
        while (new_n != 1)
        {
            cout << new_n << endl;
            if (record.count(new_n) != 0)
            {
                return false;
            }
            record.insert(new_n);
            new_n = compute(new_n);
        }
        return true;
    }
    int compute(int n)
    {
        int count = 0;
        int tmp = 0;
        while (n != 0)
        {
            tmp = n % 10;
            count += tmp * tmp;
            n = (n - tmp) / 10;
        }
        return count;
    }
};