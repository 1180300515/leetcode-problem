#include <vector>
#include <map>

using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        record.emplace_back(val);
        min_record[val]++;
    }

    void pop()
    {
        int top = record.back();
        record.pop_back();
        min_record[top]--;
        if (min_record[top] == 0)
        {
            min_record.erase(top);
        }
    }

    int top()
    {
        return record.back();
    }

    int getMin()
    {
        return min_record.begin()->first;
    }

private:
    vector<int> record;
    map<int, int> min_record;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */