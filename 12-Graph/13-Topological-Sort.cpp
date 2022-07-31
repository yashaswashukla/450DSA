/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/topological-sort/1
*/

/**
 */
class dfsSolution
{
	void topoDfs(int i, vector<int> adj[], vector<int> &visited, stack<int> &st)
	{
		visited[i] = 1;

		for (auto x : adj[i])
		{
			if (!visited[x])
				topoDfs(x, adj, visited, st);
		}
		st.push(i);
	}

	vector<int> topoSort(int V, vector<int> adj[])
	{
		stack<int> st;
		vector<int> visited(V, 0);

		for (int i = 0; i < V; i++)
		{
			if (!visited[i])
				topoDfs(i, adj, visited, st);
		}

		vector<int> answer;
		while (!st.empty())
		{
			answer.push_back(st.top());
			st.pop();
		}

		return answer;
	}
};

class bfsSolution
{
	vector<int> Kahn(int V, vector<int> adj[])
	{
		queue<int> q;
		vector<int> inDegree(V, 0);
		vector<int> ans;

		for (int i = 0; i < V; i++)
		{
			for (auto x : adj[i])
				inDegree[x]++;
		}

		for (int i = 0; i < inDegree.size(); i++)
		{
			if (inDegree[i] == 0)
				q.push(i);
		}

		while (!q.empty())
		{
			int node = q.front();
			ans.push_back(node);
			q.pop();

			for (auto x : adj[node])
			{
				inDegree[x]--;
				if (!inDegree[x])
					q.push(x);
			}
		}

		return ans;
	}
};