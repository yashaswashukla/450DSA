/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

/**
 */
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool cyclicDfs(int i, int parent, vector<int> adj[], vector<int> &visited)
    {
        visited[i] = 1;

        for (auto x : adj[i])
        {
            if (!visited[x])
            {
                if (cyclicDfs(x, i, adj, visited))
                    return true;
            }
            else
            {
                if (x != parent)
                    return true;
            }
        }

        return false;
    }

    bool cyclicBfs(int t, int parent, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> q;
        q.push({i, parent});
        visited[i] = 1;
        while (!q.empty())
        {
            int node = q.front().first();
            int parent = q.front().second();
            q.pop();

            for (auto x : adj[node])
            {
                if (!visited[x])
                {
                    q.push({x, node});
                    visited[x] = 1;
                }
                else if (x != parent)
                    return true;
            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (cyclicDfs(i, -1, adj, visited))
                    return true;
        }

        return false;
    }
}