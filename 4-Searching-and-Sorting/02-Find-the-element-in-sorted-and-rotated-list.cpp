/*
LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array/
GFG: https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1/
*/

/**
 * The idea is simple, that we find the pivot point and how to do that
 * Pivot will be the only element in a sorted list where it's next element will be smaller than it
 * Hence, we will use this condition to find the index of the element
 *
 * Then after finding the point of pivot, if the element is smaller than the first value of the list
 * we will search in the right sub-array. But if it is greater than the first element we search in the left sub-array
 *
 */
class basicSolution
{
    int binarySearch(int arr[], int low, int high, int x)
    {
        if (high < low)
            return -1;

        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (key == arr[mid])
            return mid;

        if (key > arr[mid])
            return binarySearch(arr, (mid + 1), high, key);

        // else
        return binarySearch(arr, low, (mid - 1), key);
    }
    int findPivot(int arr[], int low, int high)
    {
        // base cases
        if (high < low)
            return -1;
        if (high == low)
            return low;

        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (mid < high && arr[mid] > arr[mid + 1])
            return mid;

        if (mid > low && arr[mid] < arr[mid - 1])
            return (mid - 1);

        if (arr[low] >= arr[mid])
            return findPivot(arr, low, mid - 1);

        return findPivot(arr, mid + 1, high);
    }

    int pivotedBinarySearch(int arr[], int low, int high, int key)
    {
        int pivot = findPivot(arr, 0, n - 1);

        // If we didn't find a pivot,
        // then array is not rotated at all
        if (pivot == -1)
            return binarySearch(arr, 0, n - 1, key);

        // If we found a pivot, then first compare with pivot
        // and then search in two subarrays around pivot
        if (arr[pivot] == key)
            return pivot;

        if (arr[0] <= key)
            return binarySearch(arr, 0, pivot - 1, key);

        return binarySearch(arr, pivot + 1, n - 1, key);
    }
};

/**
1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..h]
4) Else (arr[mid+1..h] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[h], recur for arr[mid+1..h].
    b) Else recur for arr[l..mid]

 */

class improvedSolution
{
    int search(int arr[], int l, int h, int key)
    {
        if (l > h)
            return -1;

        int mid = (l + h) / 2;
        if (arr[mid] == key)
            return mid;

        /* If arr[l...mid] is sorted */
        if (arr[l] <= arr[mid])
        {
            /* As this subarray is sorted, we can quickly
            check if key lies in half or other half */
            if (key >= arr[l] && key <= arr[mid])
                return search(arr, l, mid - 1, key);
            /*If key not lies in first half subarray,
               Divide other half  into two subarrays,
               such that we can quickly check if key lies
               in other half */
            return search(arr, mid + 1, h, key);
        }

        /* If arr[l..mid] first subarray is not sorted, then
        arr[mid... h] must be sorted subarray */
        if (key >= arr[mid] && key <= arr[h])
            return search(arr, mid + 1, h, key);

        return search(arr, l, mid - 1, key);
    }
}