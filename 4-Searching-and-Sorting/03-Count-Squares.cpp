/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/count-squares3649/1
*/

/**
 */
class Solution
{
    int countSquares(int N)
    {
        // code here
        int i = 1;
        int count = 0;

        while (i * i < N)
        {
            count++;
            i++;
        }
        return count;
    }
}