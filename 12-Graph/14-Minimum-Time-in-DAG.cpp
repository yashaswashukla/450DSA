/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1
*/

/**
 */
class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
    {
        vector<int> dis(n + 1, INT_MIN);
        vector<int> adj[n + 1];
        vector<int> inDegree(n + 1, 0);
        queue<int> q;

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!inDegree[i])
            {
                q.push(i);
                dis[i] = 1;
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            int prevDis = dis[node];
            q.pop();

            for (auto next : adj[node])
            {
                inDegree[next]--;

                if (!inDegree[next])
                    q.push(next);

                if (prevDis + 1 > dis[next])
                    dis[next] = prevDis + 1;
            }
        }
        dis.erase(dis.begin());

        return dis;
    }
}