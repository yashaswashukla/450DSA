/*
LeetCode:
GFG:https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1/
*/

/**
 */
class Solution
{
    int search(int arr[], int n, int x, int k)
    {
        int i = 0;
        while (i < n)
        {
            if (arr[i] == x)
                return i;
            else
            {
                int difference = abs(arr[i] - x);
                int jump = difference / k;
                i = i + max(1, jump);
            }
        }
            return -1;
    }
}