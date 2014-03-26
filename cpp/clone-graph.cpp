/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    map<int, bool> visited;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
            
        map<int, UndirectedGraphNode*> visited;
        return dfs(node, visited);
    }
    
    UndirectedGraphNode* dfs(UndirectedGraphNode* node, map<int, UndirectedGraphNode*> &visited)
    {
        UndirectedGraphNode* n = new UndirectedGraphNode(node->label);
        visited[n->label] = n;
        for(int i = 0; i < node->neighbors.size(); i++)
        {
            if(!visited[node->neighbors[i]->label])
            {
                n->neighbors.push_back(dfs(node->neighbors[i], visited));
            }
            else
                n->neighbors.push_back(visited[node->neighbors[i]->label]);
        }
        return n;
    }
};
