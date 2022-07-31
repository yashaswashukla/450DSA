/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/

/**
 */
class Solution
{
public:
    void dfs(int i, vector<int> adj[], vector<int> &answer, vector<int> &visited)
    {
        if (!visited[i])
        {
            answer.push_back(i);
            visited[i] = 1;

            for (auto x : adj[i])
                dfs(x, adj, answer, visited);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> answer;
        vector<int> visited(V, 0);

        dfs(0, adj, answer, visited);

        return answer;
    }
}