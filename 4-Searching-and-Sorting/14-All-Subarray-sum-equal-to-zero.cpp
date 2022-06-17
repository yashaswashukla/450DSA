/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
*/

/**
 */
class bruteForceSolution // O(n^2) & S(1)
{
    int findSubArray(vector<int> arr, int k)
    {
        // This is a solution for finding subarray sum equal to k
        // For this question k=0;
        k = 0;
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = arr[i];

            if (sum == k)
                count++;

            for (int j = i + 1; j < n; j++)
            {
                sum += arr[j];
                if (sum == k)
                    count++;
            }
        }

        return count;
    }
};

/**
 * Maintain sum of elements encountered so far in a variable (say sum).
 * If current sum is 0, we found a subarray starting from index 0 and ending at index current index
 * Check if current sum exists in the hash table or not.
 * If current sum already exists in the hash table then it indicates that this sum was the sum of some sub-array elements arr[0]…arr[i] and now the same sum is obtained for the current sub-array arr[0]…arr[j] which means that the sum of the sub-array arr[i+1]…arr[j] must be 0.
 * Insert current sum into the hash table
 *
 */

class hashingSolution // O(n) & S(n)
{
    int findSubArray(vector<int> arr, int k)
    {
        k = 0;
        int n = arr.size();
        int count = 0;
        unordered_map<long long, long long> map;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == k)
                count++;

            if (map.find(sum - k) != map.end())
                count += map[sum - k];

            map[sum]++;
        }
        return count;
    }
}