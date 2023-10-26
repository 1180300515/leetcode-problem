#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        int temp = 0;
        bool begin = false;
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            if (!begin)
            {
                if (prices[i + 1] - prices[i] > 0)
                {
                    result = result > prices[i + 1] - prices[i] ? result : prices[i + 1] - prices[i];
                    if (i + 2 < prices.size() && prices[i + 2] - prices[i] > 0)
                    {
                        begin = true;
                        temp = prices[i + 1] - prices[i];
                    }
                }
            }
            else
            {
                int k = prices[i + 1] - prices[i];
                temp += k;
                if (temp > result)
                {
                    result = temp;
                }
                if (k > result)
                {
                    result = k;
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    vector<int> boxTypes = {1,2,4,2,5,7,2,4,9,0,9};
    Solution solution;
    int result = solution.maxProfit(boxTypes);
    cout << result << endl;
    return 0;
}