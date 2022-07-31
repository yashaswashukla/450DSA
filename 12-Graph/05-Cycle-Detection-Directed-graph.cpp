/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

/**
 * Keeping an array naming dfsvis which will keep track of the elements in the dfs visit, and undo the change while returning from the dfs
 * So, if the visited[x] and dfsVis[x] are 1 then that means there is a cycle in the graph
 *
 */
class dfsSolution
{
    bool cyclicDfs(int i, vector<int> adj[], vector<int> &visited, vector<int> &dfsvis)
    {
        visited[i] = 1;
        dfsvis[i] = 1;

        for (auto x : adj[i])
        {
            if (!visited[x])
            {
                if (cyclicDfs(x, adj, visited, dfsvis))
                    return true;
            }
            else if (dfsvis[x])
                return true;
        }

        dfsvis[i] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {

        vector<int> visited(V, 0);
        vector<int> dfsvis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (cyclicDfs(i, adj, visited, dfsvis))
                    return true;
        }

        return false;
    }
};

/**
 * As we already know, Kahn's Algorithm for topological sort can only be used for DAG (Directed Acyclic Graph)
 * So, if we are not able to generate the Topological order for any graph that means it is Cyclic
 *
 */
class bfsSolution
{
    bool kahns(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        queue<int> q;
        vector<int> answer;

        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
                inDegree[x]++;
        }

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            answer.push_back(node);
            q.pop();

            for (auto x : adj[node])
            {
                inDegree[x]--;
                if (!inDegree[x])
                    q.push(x);
            }
        }

        if (answer.size() == V)
            return false;
        return true;
    }
}