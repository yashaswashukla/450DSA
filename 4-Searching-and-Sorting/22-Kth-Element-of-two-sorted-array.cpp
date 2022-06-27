/*
LeetCode:
GFG:https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
*/

/**
 * Intuition behind this solution is to merge the two array only till kth place
 * without using an extra array for storage
 *
 */
class naiveSolution // O(k)&S(1)
{
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0;
        int j = 0;
        int count = 0;

        // Finding the smaller element of the two arrays and incrementing the array
        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                count++;
                if (count == k)
                    return arr1[i];
                i++;
            }
            else
            {
                count++;
                if (count == k)
                    return arr2[j];
                j++;
            }
        }
        // If arr2 is over

        while (i < n)
        {
            count++;
            if (count == k)
                return arr1[i];
            i++;
        }

        // If arr1 is over
        while (j < m)
        {
            count++;
            if (count == k)
                return arr2[j];
            j++;
        }
    }
};

/**
 * The intution behind this solution is to search for the number of elements we can get from the smaller array and the rest of the elements
 * will be from the larger array.
 * Approach:
 * Apply binary search in an array with a small size. Start iterating with two pointers, say left and right. Find the middle of the range.
 * Take elements from low to middle of array1 and the remaining elements from the second array.
 * Then using the condition mentioned above, check if the left half is valid.
 * If valid, print the maximum of both array’s last element.
 * If not, move the range towards the right if l2 > r1, else move the range towards the left if l1 > r2.
 *
 */

class optimalSolution
{
    int kthElement(int arr1[], int arr2[], int n, int m, int k) // O(min(logn,logm))
    {

        // If the size of the first array is smaller than the second array
        if (n > m)
        {
            return kthElement(arr2, arr1, m, n, k);
        }

        // The conditions of taking low and high, after considering the two edge cases

        // The minimum elements we can take from the first array will be 0, if and only if k<m.
        // But if k>m then we have to take atleast k-m elements from the first array

        int low = max(0, k - m);

        // Similarly the maximum elements we can take from first array will be it's entire length which is n.
        // But if k is smaller than n then we can only take at max k elements

        int high = min(k, n);

        while (low <= high)
        {
            int cut1 = (low + high) / 2;
            // Another method of dividing any number by 2
            // int cut1=(low+high)>>1

            // We will take the remaining elements from the second array
            int cut2 = k - cut1;

            // If cut1==0 then cut1-1=-1 that will give an error hence fixing that
            // INT_MIN, so that our conditions stay valid
            int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];

            // Similarly, if the cuts are at the end of the list then that will be out of range error
            // INT_MAX so that if the cut are at the last, it will satisfy our condition
            int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            // Shifting to the left
            else if (l1 > r2)
                high = cut1 - 1;
            // Shifting to the right
            else
                low = cut1 + 1;
        }
    }
}