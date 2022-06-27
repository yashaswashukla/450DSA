/*
    Problem Link(s): * https://leetcode.com/problems/spiral-matrix/
                     * https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

    Explanation : https://www.youtube.com/watch?v=siKFOI8PNKM

    we will take 4 pointers
    Top
    Bottom
    Left
    Right

    This will be their initial position.
            L     R
            ⬇     ⬇
    T -->   X X X X
            X X X X
            X X X X
            X X X X
    B -->   X X X X

    we will move in given order and push elements into our answer list
    while(L<=R && T<=B):
        L->R
        T->B
        --> here we will add a special check to avoid repepetition of answers
        R->L
        B->T
    After each step we will Increase/descrease the origin pointer.
    * also watch out edge cases like, row only and column only matrix.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {

        // Direction 1: Traversing the top row from left to right
        // Direction 2: Traversing the right column from top to bottom
        // Direction 3: Traversing the bottom row from right to left
        // Direction 4: Traversing the left column from bottom to top

        if (r == 0)
            return {};

        int top = 0, bottom = r - 1, left = 0, right = c - 1;

        vector<int> answer;

        while (top <= bottom && left <= right)
        {
            // Direction 1:

            for (int i = left; i <= right; i++)
            {
                answer.push_back(matrix[top][i]);
            }
            top++;

            // Direction 2:

            for (int i = top; i <= bottom; i++)
            {
                answer.push_back(matrix[i][right]);
            }
            right--;

            // Before going further checking the edge cases

            if (top > bottom or left > right)
                break;

            // Direction 3:

            for (int i = right; i >= left; i--)
            {
                answer.push_back(matrix[bottom][i]);
            }
            bottom--;

            // Direction 4:

            for (int i = bottom; i >= top; i--)
            {
                answer.push_back(matrix[i][left]);
            }
            left++;
        }

        return answer;
    }
};

int main()
{
    vector<vector<int>> Matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> m{{1, 2}, {3, 4}};

    /*
        1 2 3   1   2   3
        4 5 6   8   9   4
        7 8 9   7   6   5
    */

    Solution ob;
    auto ok = ob.spiralOrder(m);

    for (auto c : ok)
        cerr << c << " ";
    cerr << endl;
}