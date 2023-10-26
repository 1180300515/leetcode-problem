#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int length = boxTypes.size();
        int tag = 0;
        int max = 0;
        int result = 0;
        while (truckSize > 0)
        {
            tag = 0;
            max = boxTypes[tag][1];
            for (int i = 0; i < length; ++i)
            {
                if (boxTypes[i][1] >= max && i != tag)
                {
                    tag = i;
                    max = boxTypes[i][1];
                }
            }
            if (truckSize >= boxTypes[tag][0])
            {
                result += boxTypes[tag][1] * boxTypes[tag][0];
                truckSize -= boxTypes[tag][0];
                boxTypes[tag][1] = 0;
            }
            else
            {
                result += boxTypes[tag][1] * truckSize;
                truckSize = 0;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    Solution solution;
    int result = solution.maximumUnits(boxTypes, 4);
    cout << result << endl;
    return 0;
}