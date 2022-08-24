/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

/**
 * Prim's Algorithm:
 * 
 * 
 */
class naiveSolution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> mst(V, false);

        parent[0] = -1, key[0] = 0;

        for (int count = 0; count < V - 1; count++)
        {
            int min = INT_MAX, u;

            for (int i = 0; i < V; i++)
                if (!mst[i] && key[i] < min)
                    min = key[i], u = i;

            mst[u] = true;

            for (auto x : adj[u])
            {
                int node = x[0];
                int weight = x[1];

                if (weight < key[node] && !mst[node])
                    key[node] = weight, parent[node] = u;
            }
        }

        int sum = 0;
        for (int i = 0; i < V; i++)
            sum += key[i];

        return sum;
    }
};

class optimalSolution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // vector<int> parent(V, -1);
        vector<bool> mst(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0;
        pq.push({0, 0});

        for (int count = 0; count < V; count++)
        {
            while (mst[pq.top().second])
                pq.pop();

            int parentNode = pq.top().second;
            sum += pq.top().first;
            pq.pop();

            mst[parentNode] = true;

            for (auto x : adj[parentNode])
            {
                int node = x[0];
                int weight = x[1];
                pq.push({weight, node});
            }
        }
        return sum;
    }
};