/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
*/

/**
 * There are other solutions which use hashing and extra space but they can be used only if we have to identify or print
 * only one set of four sums.
 * Article can be found on this link:
 * https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
 *
 */
class TwoPointerSolution // O(n^3+nLogn) & S(1)
{
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Answer Vector
        vector<vector<int>> answer;
        // Sort the array to apply two pointer
        sort(arr.begin(), arr.end());
        int n = arr.size();

        // Loop for the first element, as we have to find four elements we will take this loop to n-3
        for (int i = 0; i < n - 3; i++)
        {
            // Loop for the second element, as we have to find four elements we will take this loop to n-2

            for (int j = i + 1; j < n - 2; j++)
            {
                // Two pointers
                int left = j + 1;
                int right = n - 1;

                int expectedSum = k - arr[i] - arr[j];

                while (left < right)
                {
                    if (arr[left] + arr[right] < expectedSum)
                        left++;
                    else if (arr[left] + arr[right] > expectedSum)
                        right--;
                    else
                    {
                        answer.push_back(vector<int>{arr[i], arr[j], arr[left], arr[right]});
                        // Removing the duplicate values from the answer
                        do
                        {
                            left++;
                        } while (arr[left] == arr[left - 1] && left < right);
                        do
                        {
                            right--;
                        } while (arr[right] == arr[right + 1] && left < right);
                    }
                }
                // Removing the duplicate elements
                while (j + 1 < n - 2 && arr[j + 1] == arr[j])
                    j++;
            }
            // Removing the duplicate values
            while (i + 1 < n - 3 && arr[i + 1] == arr[i])
                i++;
        }
        return answer;
    }
};
