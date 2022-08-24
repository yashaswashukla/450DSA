/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/

class bfsSolution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        queue<int> q;
        vector<int> vis(V, INT_MAX);

        // q.push({0,S});

        q.push(S);
        vis[S] = 0;

        while (!q.empty())
        {
            // int prevdis=q.top().first;
            // int node=q.top().second;

            int node = q.front();
            int prevdis = vis[node];
            q.pop();
            for (auto items : adj[node])
            {
                int nextNode = items[0];
                int nextDis = items[1];
                if (nextDis + prevdis < vis[nextNode])
                {
                    vis[nextNode] = nextDis + prevdis;
                    // q.push({nextDis+prevdis, nextNode});
                    q.push(nextNode);
                }
            }
        }

        return vis;
    }
}