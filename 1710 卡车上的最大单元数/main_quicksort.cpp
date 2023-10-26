#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int length = boxTypes.size();
        vector<int> sort(length);
        for (int i = 0; i < length; ++i)
        {
            sort[i] = i;
        }
        QuickSort(sort, boxTypes, 0, length - 1);

        for (int i = 0; i < length; ++i)
        {
            cout << sort[i] << endl;
        }

        int flag = length - 1;
        int result = 0;
        while (truckSize > 0 && flag >= 0)
        {
            if (truckSize >= boxTypes[sort[flag]][0])
            {
                result += boxTypes[sort[flag]][1] * boxTypes[sort[flag]][0];
                truckSize -= boxTypes[sort[flag]][0];
            }
            else
            {
                result += boxTypes[sort[flag]][1] * truckSize;
                truckSize = 0;
            }
            --flag;
        }
        return result;
    }
    void QuickSort(vector<int> &sortresult, vector<vector<int>> &boxTypes, int low, int high)
    {
        if (low < high)
        {
            int pivot = Paritition1(sortresult, boxTypes, low, high);
            QuickSort(sortresult, boxTypes, low, pivot - 1);
            QuickSort(sortresult, boxTypes, pivot + 1, high);
        }
    }
    int Paritition1(vector<int> &sortresult, vector<vector<int>> &boxTypes, int low, int high)
    {
        int pivot = sortresult[low];
        while (low < high)
        {
            while (low < high && boxTypes[sortresult[high]][1] >= boxTypes[pivot][1])
            {
                --high;
            }
            sortresult[low] = sortresult[high];
            while (low < high && boxTypes[low][1] <= boxTypes[pivot][1])
            {
                ++low;
            }
            sortresult[high] = sortresult[low];
        }
        sortresult[low] = pivot;
        return low;
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> boxTypes = {{1,3},{2,2},{3,1}};
    Solution solution;
    int result = solution.maximumUnits(boxTypes,4);
    cout << result << endl;
    return 0;
}