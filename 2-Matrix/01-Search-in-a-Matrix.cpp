/*
LeetCode:
GFG:
*/

/**
 */
class naiveSolution // O(m+n)
{
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // running a for loop till size of matrix
        for (int i = 0; i < matrix.size(); ++i)
        {
            // nested for for ietrating each row element
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                // if found return true
                if (matrix[i][j] == target)
                    return true;
            }
        }
        // after traversal if not found
        // return false
        return false;
    }
};

class binarySearchSolution // O(log(m*n))
{
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // if matrix have 0 rows or 0 columns
        if (n == 0 || m == 0)
            return false;

        // treating matrix as array just taking care of indices
        // [0..n*m]
        int start = 0, end = m * n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            // a[x] : matrix[x / m][x % m] formulae
            int ind = matrix[mid / m][mid % m];
            if (target == ind)
                return true;
            // left half
            else if (target < ind)
                end = mid - 1;
            else
                // right half
                start = mid + 1;
        }
        return false;
    }
};
