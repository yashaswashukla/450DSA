/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
*/

/**
 */
class bfsSolution
{
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        queue<int> q;
        int prevColor = 0;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                q.push(i);
                color[i] = prevColor;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (auto x : adj[node])
                    {
                        if (color[x] == -1)
                        {
                            color[x] = !color[node];
                            q.push(x);
                            // cout<<"Color of node is "<<color[node]<<endl<<"Color of x is: "<<color[x]<<endl;
                        }
                        if (color[x] == color[node])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};

class dfsSolution
{
    bool dfs(int node, int c, vector<int> adj[], vector<int> &color)
    {
        color[node] = c;

        for (auto x : adj[node])
        {
            if (color[x] == -1)
            {
                if (!dfs(x, !c, adj, color))
                    return false;
            }
            if (color[x] == color[node])
                return false;
        }

        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, 1, adj, color))
                    return false;
            }
        }
        return true;
    }
}