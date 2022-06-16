/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#
*/

/**
 */
class Solution
{
    long long countTriplets(long long arr[], int n, long long sum)
    {
        long long count = 0;
        // Sorting the array

        sort(arr, arr + n);

        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int tripletSum = arr[i] + arr[left] + arr[right];
                if (tripletSum < sum)
                {
                    // If the triplet sum is less than sum in the range left to right
                    // That means all the the pairs in the range left to right have the triplet sum less than sum
                    count = count + right - left;
                    left++;
                }
                // If the sum is greater than or equal to the given sum then we decrement the right pointer as we have to find the triplet sum < given sum
                else
                    right--;
            }
        }

        return count;
    }
}