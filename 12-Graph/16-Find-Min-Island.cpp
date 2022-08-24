/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/

/**
 */
class Solution
{
private:
    int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        grid[i][j] = '2';

        for (int k = 0; k < 8; k++)
        {
            int ni = i + y[k], nj = j + x[k];

            if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size())
            {
                if (grid[ni][nj] == '1')
                {
                    dfs(ni, nj, grid);
                }
            }
        }
    }

public:
    // Function to find the number of islands.

    int numIslands(vector<vector<char>> &grid)
    {
        int island = 0;
        int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> vis(n, vector<int>(m,0));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    island++;
                    dfs(i, j, grid);
                }
            }
        }

        return island;
    }
};