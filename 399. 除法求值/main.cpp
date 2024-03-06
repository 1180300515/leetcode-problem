#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> list_; 
        int count = 0;  
        for(int i = 0; i < equations.size(); ++i){
            string fen_zi = equations[i][0];
            string fen_mu = equations[i][1];
            if (list_.count(fen_zi) == 0){
                list_[fen_zi] = count;
                count++;
            }
            if (list_.count(fen_mu) == 0) {
                list_[fen_mu] = count;
                count++;
            }
        }
        vector<vector<double>> map_(count, vector<double>(count,0.0));
        for(int i = 0; i < equations.size(); ++i) {
            int fenzi = list_[equations[i][0]];
            int fenmu = list_[equations[i][1]];
            map_[fenzi][fenmu] = values[i];
            map_[fenmu][fenzi] = 1.0 / values[i];
        }
        //cout << "there" << endl;
        vector<double> result;
        for(int i = 0; i < queries.size(); ++i) {
            if (list_.count(queries[i][0]) == 0 || list_.count(queries[i][1]) == 0) {
                result.emplace_back(-1.0);
                continue;
            }
            std::unordered_set<int> log_;
            if (!dfs(map_,list_,result,log_,list_[queries[i][0]],list_[queries[i][1]], 1.0)) {
                result.emplace_back(-1.0);
            }
        }
        return result;
        
    }
    bool dfs(vector<vector<double>> &map_, unordered_map<string,int> &list_, vector<double> &result, 
                std::unordered_set<int> &log_, int begin, int end , double cur) {
        //cout << begin << "  " <<  end << "  " << cur << endl;
        log_.insert(begin);
        if (begin == end) {
            result.emplace_back(cur);
            return true;
        }
        bool has_result = false;
        for(int i = 0 ; i < map_[begin].size(); ++i){
            if(map_[begin][i] != 0.0 && log_.count(i) == 0) {   
                has_result |= dfs(map_,list_,result,log_,i,end,cur * map_[begin][i]);               
            }
        }
        return has_result;
    }
};