/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
*/

/**
 */
class bfsSolution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        unordered_map<Node *, Node *> map;
        map[node] = new Node(node->val);

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            for (int i = 0; i < temp->neighbors.size(); i++)
            {
                if (map.find(temp->neighbors[i]) == map.end())
                {
                    map[temp->neighbors[i]] = new Node(temp->neighbors[i]->val);
                    q.push(temp->neighbors[i]);
                }
                map[temp]->neighbors.push_back(map[temp->neighbors[i]]);
            }
        }

        return map[node];
    }
};
class dfsSolution
{
private:
    unordered_map<Node *, Node *> map;

public:
    void dfs(Node *curr)
    {
        map[curr] = new Node(curr->val);

        for (int i = 0; i < curr->neighbors.size(); i++)
        {
            if (map.find(curr->neighbors[i]) == map.end())
            {
                dfs(curr->neighbors[i]);
            }
            map[curr]->neighbors.push_back(map[curr->neighbors[i]]);
        }
        return;
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        dfs(node);
        return map[node];
    }
};