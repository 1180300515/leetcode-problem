#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        {
            return nullptr;
        }
        return dfs(node);        
    }

    Node* dfs(Node* node)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        if (record.count(node->val) == 0)
        {
            Node* new_node = new Node(node->val);
            record[new_node->val] = new_node;
            for(auto iter: node->neighbors)
            {
                new_node->neighbors.emplace_back(dfs(iter));
            }
            return new_node;
        }
        else
        {
            return record[node->val];
        }

    }
private:
    unordered_map<int, Node*> record;
};