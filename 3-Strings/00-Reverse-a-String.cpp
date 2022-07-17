/*
LeetCode: https://leetcode.com/problems/reverse-string/submissions/
GFG:
*/

/**
 */
class Solution // O(n) & S(1)
{
    void swap(char *a, char *b)
    {
        char temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            swap(&s[left], &s[right]);
            left++;
            right--;
        }
    }
}