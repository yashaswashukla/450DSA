/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#
*/

/**
 */
class Solution
{
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {

        long long product = 1;
        int countZero = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
                product = product * nums[i];
            else
                countZero++;
        }

        vector<long long> answer(n, 0);
        if (countZero > 1)
            return answer;
        for (int i = 0; i < n; i++)
        {
            if (countZero > 0)
            {
                if (nums[i])
                    answer[i] = 0;
                else
                    answer[i] = product;
            }
            else
            {
                answer[i] = product / nums[i];
            }
        }

        return answer;
    }
}