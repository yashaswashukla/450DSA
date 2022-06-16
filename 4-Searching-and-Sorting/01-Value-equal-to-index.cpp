/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1#
*/

/**
 */
class Solution
{
    vector<int> valueEqualToIndex(int arr[], int n)
    {
        vector<int> answer;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == i + 1)
                answer.push_back(i + 1);
        }
        return answer;
    }
}