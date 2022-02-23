/*
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        unordered_map<Node*,Node*>G;
        queue<Node*>q;
        G[node] = new Node(node->val);
        q.push(node);
        while(!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            vector<Node*>&child = cur->neighbors;
            for(int i = 0; i < child.size(); i++)
            {
                if(G.find(child[i]) == G.end())
                {
                    G[child[i]] = new Node(child[i]->val);
                    q.push(child[i]);
                }
                G[cur]->neighbors.push_back(G[child[i]]);
            }
        }
        return G[node];
    }
};