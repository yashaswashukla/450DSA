/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
*/

/**
 */
class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[])
    {
        vector<vector<int>> answer(V);

        for (int i = 0; i < V; i++)
        {
            answer[i].push_back(i);
            for (auto x : adj[i])
                answer[i].push_back(x);
        }

        return answer;
    }
}