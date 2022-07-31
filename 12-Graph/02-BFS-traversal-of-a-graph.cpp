/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

/**
 */
class Solution
{
public:
    void bfs(int i, vector<int> adj[], vector<int> &answer, vector<int> &visited)
    {
        queue<int> que;
        answer.push_back(i);
        que.push(i);
        while (!que.empty())
        {
            int j = que.front();
            que.pop();
            for (auto x : adj[j])
            {
                if (!visited[x])
                {
                    visited[x] = 1;
                    que.push(x);
                    answer.push_back(x);
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);
        vector<int> answer;

        if (!visited[0])
            bfs(0, adj, answer, visited);

        return answer;
    }
}