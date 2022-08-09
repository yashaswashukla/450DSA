/*
LeetCode:
GFG:https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

/**
 */
class Solution
{
    vector<string> ans;
    void dfs(int i, int j, int n, string s, vector<vector<int>> &vis, vector<vector<int>> &m)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            return;
        }

        // Down
        if (i + 1 < n && vis[i + 1][j] != 1 && m[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            dfs(i + 1, j, n, s + 'D', vis, m);
            vis[i][j] = 0;
        }

        // Left
        if (j - 1 >= 0 && vis[i][j - 1] != 1 && m[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            dfs(i, j - 1, n, s + 'L', vis, m);
            vis[i][j] = 0;
        }

        // Right
        if (j + 1 < n && vis[i][j + 1] != 1 && m[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            dfs(i, j + 1, n, s + 'R', vis, m);
            vis[i][j] = 0;
        }

        // Up
        if (i - 1 >= 0 && vis[i - 1][j] != 1 && m[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            dfs(i - 1, j, n, s + 'U', vis, m);
            vis[i][j] = 0;
        }

        return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 0)
            return {};
        if (m[n - 1][n - 1] == 0)
            return {};

        dfs(0, 0, n, "", vis, m);

        return ans;
    }
}