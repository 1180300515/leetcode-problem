#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;
        record[nums[0]] = 0;
        int i = 1;
        while (true)
        {
            if (i == nums.size())
            {
                return false;
            }
            if (record.count(nums[i]) == 0)
            {
                record[nums[i]] = i;
            }
            else if (i - record[nums[i]] <= k)
            {
                return true;
            }
            else
            {
                record[nums[i]] = i;
            }
            i++;
        }
    }
};