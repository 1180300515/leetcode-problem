#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int num = matrix.size() * matrix.size();
        vector<int> history(num,0);
        int count;
        int value;
        int record = 0;
        int x = 0;
        int y = 0;
        int old_x;
        bool tag = true;
        while(true)
        { 
            tag = true;
            for(int i = 0 ; i < num ; ++i)
            {
                if (history[i] == 0)
                {
                    y = i % matrix.size();
                    x = (int)i / matrix.size();
                    value = matrix[x][y];
                    tag =false;
                }
            }
            if (tag)
            {
                break;
            }
            count = 0;
            while (count < 4)
            {
                old_x = x;
                x = y;
                y = matrix.size() - 1 - old_x;
                record = matrix[x][y];
                matrix[x][y] = value;
                history[x*matrix.size() + y] = 1;
                value = record;
                count++;
            }
        }
    }
};
int main(int argc, char **argv)
{
    vector<vector<int>> boxTypes ={{1,2,3},{4,5,6},{7,8,9}};
    Solution solution;
    solution.rotate(boxTypes);
    for (auto iter: boxTypes)
    {
        for(auto item : iter)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}