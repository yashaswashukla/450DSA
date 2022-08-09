/*
LeetCode:
GFG:https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
*/

/**
 */
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &Targetpos, int N)
    {
        int x[8] = {1, -1, 1, -1, 2, 2, -2, -2};
        int y[8] = {2, 2, -2, -2, 1, -1, 1, -1};
        vector<vector<int>> vis(N + 1, vector<int>(N + 1, -1));

        queue<pair<int, int>> q;
        vis[KnightPos[0]][KnightPos[1]] = 0;

        q.push({KnightPos[0], KnightPos[1]});

        while (!q.empty())
        {
            pair<int, int> pos = q.front();
            q.pop();

            if (pos.first == Targetpos[0] && pos.second == Targetpos[1])
                return vis[pos.first][pos.second];

            for (int i = 0; i < 8; i++)
            {
                int targetx = pos.first + x[i];
                int targety = pos.second + y[i];

                if (targetx <= N && targetx > 0 && targety <= N && targety > 0)
                {
                    if (vis[targetx][targety] == -1)
                    {
                        q.push({targetx, targety});
                        vis[targetx][targety] = vis[pos.first][pos.second] + 1;
                    }
                }
            }
        }
    }
}