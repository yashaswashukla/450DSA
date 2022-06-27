/*
LeetCode:
GFG:
*/

/**
 */
class bruteForceSolution // O(n^2log(n)) && S(n^2)
{
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> Mat)
    {
        vector<int> temp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(Mat[i][j]);
            }
        }

        sort(temp.begin(), temp.end());
        int k = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                Mat[i][j] = temp[k++];

        return Mat;
    }
};

/**
 *
 *
 */

class optimalSolution //O((m*n)^2) & S(1)
{
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> Mat)
    {
        // This will work for any size of matrix
        int row = n, col = n;
        // Number of elements in matrix
        int size = col * row;

        // Loop to sort the matrix
        // using Bubble Sort
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {

                // Condition to check
                // if the Adjacent elements
                if (Mat[j / col][j % col] > Mat[(j + 1) / col][(j + 1) % col])
                {

                    // Swap if previous value is greater
                    int temp = Mat[j / col][j % col];
                    Mat[j / col][j % col] = Mat[(j + 1) / col][(j + 1) % col];
                    Mat[(j + 1) / col][(j + 1) % col] = temp;
                }
            }
        }

        return Mat;
    }
};