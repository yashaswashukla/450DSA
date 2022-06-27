/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
*/

/**
 */
class bruteForceSolution // O(m*n)
{
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int row = -1;
        int maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            int rowCount = 0;
            for (int j = 0; j < m; j++)
            {

                if (arr[i][j] == 1)
                    rowCount++;
            }

            if (rowCount > maxCount)
            {
                maxCount = rowCount;
                row = i;
            }
        }

        return row;
    }
};

/**
 * Assume, we have a matrix:
 * 0 0 0 1
 * 0 0 1 1
 * 0 0 0 0
 * 1 1 1 1
 *
 * In the first iteration:
 * i -> 0 0 0 1, j will be at 3 and max row with 1 will be at 0
 *      0 0 1 1
 *      0 0 0 0
 *      1 1 1 1
 * now in the next iteration i =1 and we will get the j =2 and hence max row with 1 will be 1
 * Similarly, we will find the left most 1 in every row but only left to previously set j
 *
 */
class optimalSolution // O(m+n)
{
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int j = m - 1, answer = 0;

        for (int i = 0; i < n; i++)
        {
            // Flag to check if the previous row has more or less number of 1s
            bool previousRowWithLess1s = false;

            // Finding the left most 1 in the row
            while (j >= 0 && arr[i][j] == 1)
            {
                j = j - 1;
                previousRowWithLess1s = true;
            }

            // If there is 1 left of previous j
            // Then we update the answer
            if (previousRowWithLess1s)
                answer = i;
        }

        // Edge case if there is no 1

        if (answer == 0 && arr[0][m - 1] == 0)
            return -1;

        return answer;
    }
}