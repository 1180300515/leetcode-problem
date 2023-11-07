#include <vector>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> result = vector<int>(ratings.size(), 0);
        result[0] = 1;
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                result[i] = result[i - 1] + 1;
            }
            else
            {
                result[i] = 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1] && result[i] <= result[i + 1])
            {
                result[i] = result[i + 1] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < result.size(); ++i)
        {
            sum += result[i];
        }
        return sum;
    }
};