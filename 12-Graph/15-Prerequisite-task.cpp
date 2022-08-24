/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1
*/

/**
 */
class Solution
{
public:
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        vector<int> adj[N];
        vector<int> inDegree(N, 0);
        queue<int> q;
        vector<int> answer;

        for (auto edges : prerequisites)
        {
            adj[edges.first].push_back(edges.second);
            inDegree[edges.second]++;
        }

        for (int i = 0; i < N; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            answer.push_back(node);
            q.pop();
            for (auto next : adj[node])
            {
                inDegree[next]--;
                if (!inDegree[next])
                    q.push(next);
            }
        }

        for (auto val : inDegree)
            if (val > 0)
                return false;
        return true;
    }
}