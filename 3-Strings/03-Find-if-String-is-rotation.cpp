/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
*/

/**
 */
class Solution
{
    bool areRotations(string s1, string s2)
    {
        if (s1.size() != s2.size())
        {
            return false;
        }
        return (s1 + s1).find(s2) != -1;
    }
};