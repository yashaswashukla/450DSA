/*
LeetCode:https://leetcode.com/problems/flood-fill/
GFG:
*/

/**
 */
class bfsSolution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;
        z` int X[4] = {1, -1, 0, 0};
        int Y[4] = {0, 0, 1, -1};

        queue<pair<int, int>> q;

        q.push({sr, sc});
        int orig_color = image[sr][sc];
        image[sr][sc] = color;

        while (!q.empty())
        {
            pair<int, int> cor = q.front();
            q.pop();

            int x = cor.first, y = cor.second;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + X[i], ny = y + Y[i];

                if (nx < image.size() && nx >= 0 && ny < image[0].size() && ny >= 0)
                {
                    if (image[nx][ny] == orig_color)
                    {
                        image[nx][ny] = color;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return image;
    }
};
class dfsSolution
{
private:
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};

public:
    void dfs(int x, int y, vector<vector<int>> &image, int orig_color, int color)
    {
        if (image[x][y] != orig_color)
            return;
        image[x][y] = color;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i], ny = y + Y[i];

            if (nx < image.size() && nx >= 0 && ny < image[0].size() && ny >= 0)
            {
                if (image[nx][ny] == orig_color)
                    dfs(nx, ny, image, orig_color, color);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;

        int orig_color = image[sr][sc];
        dfs(sr, sc, image, orig_color, color);
        return image;
    }
}