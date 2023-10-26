#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> result;
        int length1 = arr1.size();
        int length2 = arr2.size();
        int i = 0;
        int j = 0;
        int tag = 0;
        while (true)
        {
            int v_1 = 0;
            int v_2 = 0;
            if (i < length1)
            {
                v_1 = arr1[length1 - 1 - i];
                ++i;
            }
            if (j < length2)
            {
                v_2 = arr2[length2 - 1 - j];
                ++j;
            }
            cout << "1: " << v_1 << endl;
            cout << "2: " << v_2 << endl;
            int sum = v_1 + v_2 + tag;
            if (sum == 2)
            {
                sum = 0;
                tag = -1;
            }
            else if (sum == 3)
            {
                sum = 1;
                tag = -1;
            }
            else if (sum == -1)
            {
                sum = 1;
                tag = 1;
            }
            else
            {
                tag = 0;
            }
            result.insert(result.begin(), sum);
            if (i == length1 && j == length2)
            {
                if (tag == -1)
                {
                    result.insert(result.begin(), 1);
                    result.insert(result.begin(), 1);
                }
                break;
            }
        }
        for (auto iter = result.begin(); iter != result.end() - 1;)
        {
            if (*iter != 0)
            {
                break;
            }
            else
            {
                result.erase(iter);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    vector<int> arr1 = {1, 0,1};
    vector<int> arr2 = {1,0,1};
    Solution so;
    vector<int> result = so.addNegabinary(arr1, arr2);
    for (auto iter : result)
    {
        cout << iter << endl;
    }
    return 0;
}