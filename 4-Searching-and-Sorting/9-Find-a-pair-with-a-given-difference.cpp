/*
LeetCode:
GFG:
*/

/**
 */
class Solution // O(nLogn)
{
    bool binarySearch(int i, int arr[], int size, int n, int index)
    {
        int low = 0, high = size - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == n && mid != index)
                return true;
            else if (arr[mid] > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
    bool findPair(int arr[], int size, int n)
    {
        sort(arr, arr + size);
        for (int i = 0; i < size; i++)
            if (binarySearch(arr[i], arr, size, arr[i] + n, i))
                return true;
        return false;
    }
}