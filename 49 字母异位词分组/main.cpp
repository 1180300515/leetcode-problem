#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        while(strs.size() != 0)
        {
            vector<string> item;
            auto begin = strs.back();
            strs.pop_back();
            item.emplace_back(begin);
            unordered_map<char,int> count;
            for(auto i : begin)
            {
                count[i]++;
            }
            for(auto iter = strs.begin(); iter != strs.end();)
            {
                auto temp = count;
                for(auto i : *iter)
                {
                    if (temp.count(i) == 0)
                    {
                        break;
                    }
                    else
                    {
                        temp[i]--;
                        if (temp[i] == 0)
                        {
                            temp.erase(i);
                        }
                    }
                }
                if (temp.size() == 0 && iter->length() == begin.length())
                {
                    item.emplace_back(*iter);
                    iter = strs.erase(iter);
                }
                else
                {
                    iter++;
                }
            }
            result.emplace_back(item);
        }
        return result;
    }
};

