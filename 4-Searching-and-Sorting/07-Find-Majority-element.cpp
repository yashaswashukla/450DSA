/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
*/

/**
 * Moore's Voting Algorithm:
 * First, we find the probable candidate for the majority element and then we check if the count of that element is greater than n/2 or not
 *
 * We start the loop with count =0 and majorityIndex=-1
 * we set the majorityIndex=0 and count =1
 * If the next element is equal to arr[majorityIndex] then count++ else count--
 * If count ==0 then we set the current element as the majorityIndext and count=1
 *
 */
class Solution // O(n) & S(1)
{
    int majorityElement(int arr[], int n)
    {
        // Keeping the track of the count of the majority index
        int count = 1;
        int majorityIndex = 0;

        // Finding the candidate for the majority element
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[majorityIndex])
                count++;
            else
            {
                count--;
                if (count == 0)
                {
                    majorityIndex = i;
                    count = 1;
                }
            }
        }

        // Checking if the candidate is the majority element or not
        count = 0;
        int answer = arr[majorityIndex];

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == answer)
                count++
        }

        if (count > n / 2)
            return answer;
        else
            return -1;
    }
}