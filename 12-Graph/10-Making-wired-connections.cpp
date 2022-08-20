/*
LeetCode: https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/
GFG:
*/

/**
 */

class dfsSolution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;

        for (auto x : adj[node])
        {
            if (!vis[x])
                dfs(x, vis, adj);
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        int wires = 0;
        vector<int> vis(n, 0);
        vector<int> adj[n];

        for (auto x : connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
                wires++;
            }
        }

        return wires - 1;
    }
};
class bfsSolution
{
private:
    void bfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto val : adj[curr])
            {
                if (!vis[val])
                {
                    q.push(val);
                }
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        int wires = 0;
        vector<int> vis(n, 0);
        vector<int> adj[n];

        for (auto x : connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
                wires++;
            }
        }

        return wires - 1;
    }
};