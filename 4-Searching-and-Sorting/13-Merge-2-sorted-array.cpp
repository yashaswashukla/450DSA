/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

This question requires us to merge the sorted array such that we don't use any extra space,
But if the extra space is allowed then we can easily make a new array of size (m+n) and then we can insert the
values in the new array
*/

/**
 * According to the question, The very last element of the first array should be smaller than any element of
 * second array.
 * Hence, We will compare all the elements starting from the last element of second array to the last element
 * of the first array.
 * If the element of arr2 is smaller than the last element of arr1 then we find the right place of arr2's element
 * in arr1 and place the last element of arr1 in place of arr2's element
 *
 * With this method we can guarantee that the arrays we will get will be sorted
 *
 */
class bruteForceSolution // O(m*n) => Worst Case & S(1)
{
    void merge(int arr1[], int n, int arr2[], int b)
    {
        int i = m - 1;

        // Starting the loop with the last element of arr2
        while (i >= 0)
        {
            int lastElement = arr1[n - 1];

            // If the last Element of arr1 is greater than arr2[i]
            if (lastElement > arr2[i])
            {
                // We find the last element which is smaller than the arr2[i]
                int j;
                for (j = n - 2; j >= 0 && arr2[i] < arr1[j]; j--)
                {
                    arr1[j + 1] = arr1[j];
                }

                // We swap the position of the last element greater than arr2[i] and arr2[i]
                arr1[j + 1] = arr2[i];
                arr2[i] = lastElement;
            }

            i--;
        }
    }
};

class betterBruteForceSolution // O(m+n(log(m+n)))
{
    void merge(int arr1[], int n, int arr2[], int m)
    {
        int i = n - 1;
        int j = 0;

        while (i >= 0 && j < m)
        {
            if (a[i] > b[j])
            {
                swap(a[i], b[j]);
                i--;
                j++;
            }
            else
                break;
        }
        sort(a, a + n);
        sort(b, b + m);
    }
};

/**
 * Using shell sort, shell sort is used in place of insertion sort if any order is given
 *
 *
 */
class bestSolution // O((n+m)log(n+m))
{
    void merge(int ar1[], int ar2[], int n, int m)
    {
        // code here
        int gap = ceil((float)(n + m) / 2);
        while (gap > 0)
        {
            int i = 0;
            int j = gap;
            while (j < (n + m))
            {
                if (j < n && ar1[i] > ar1[j])
                {
                    swap(ar1[i], ar1[j]);
                }
                else if (j >= n && i < n && ar1[i] > ar2[j - n])
                {
                    swap(ar1[i], ar2[j - n]);
                }
                else if (j >= n && i >= n && ar2[i - n] > ar2[j - n])
                {
                    swap(ar2[i - n], ar2[j - n]);
                }
                j++;
                i++;
            }
            if (gap == 1)
            {
                gap = 0;
            }
            else
            {
                gap = ceil((float)gap / 2);
            }
        }
    }
}