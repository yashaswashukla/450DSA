/*
LeetCode:
GFG:https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
*/

/**
 * Assume the missing number to be X and the repeating one to be Y.

Now since the numbers are from 1 to N in the array arr[]. Let’s calculate sum of all integers from 1 to N and sum of squares of all integers from 1 to N. These can easily be done using mathematical formulae.

Therefore,

Sum of all elements from 1 to N:

S = N*(N+1)/2 ---- equation 1
And, Sum of squares of all elements from 1 to N:

P = N(N+1)(2N+1)/6. ----- equation 2
Similarly, find the sum of all elements of the array and sum of squares of all elements of the array respectively.

s1 = Sum of all elements of the array. —– equation 3
P1 = Sum of squares of all elements of the array. ——– equation 4
Now, if we subtract the sum of all elements of array from sum of all elements from 1 to N, that should give us the value for (X – Y).

Therefore,

(X-Y) = s – s1 = s’

Similarly,

X^2 – Y^2 = P – P1 = P’

or, (X + Y)(X – Y) = P’

or, (X + Y)*s’ = P’

or, X + Y = P’/s’

Great,

we have the two equations we needed:

(X – Y) = s’

(X + Y) = P’/s’

We can use the two equations to solve and find values for X and Y respectively.
 */
class mathSolution // O(n) & S(1)
{
    int *findTwoElement(int *A, int n)
    {

        int S = (n * (n + 1)) / 2;
        int P = (n * (n + 1) * (2 * n + 1)) / 6;
        int missingNumber = 0, repeating = 0;

        for (int i = 0; i < n; i++)
        {
            S -= A[i];
            P -= A[i] * A[i];
        }

        missingNumber = (S + P / S) / 2;

        repeating = missingNumber - S;

        int *ans = new int(2);
        ans[0] = repeating;
        ans[1] = missingNumber;
        return ans;
    }
}