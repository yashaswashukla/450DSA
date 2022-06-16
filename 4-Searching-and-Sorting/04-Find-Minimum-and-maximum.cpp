/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1/
*/

/**
 *Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.
 *
 */
class recSolution // O(n) & S(log n) as recursive stack, Total Comparison=3n/2-2
{
    pair<long long, long long> minMax(long long arr[], int low, int high)
    {
        pair<long long, long long> answer, minMaxleft, minMaxRight;
        int mid = (low + high) / 2;

        if (low == high)
        {
            answer.second = arr[low];
            answer.first = arr[low];
            return answer;
        }

        if (low == high - 1)
        {
            if (arr[low] > arr[high])
            {
                answer.second = arr[low];
                answer.first = arr[high];
            }
            else
            {
                answer.second = arr[high];
                answer.first = arr[low];
            }
            return answer;
        }

        minMaxleft = minMax(arr, low, mid);
        minMaxRight = minMax(arr, mid + 1, high);

        if (minMaxleft.second > minMaxRight.second)
            answer.second = minMaxleft.second;
        else
            answer.second = minMaxRight.second;

        if (minMaxleft.first < minMaxRight.first)
            answer.first = minMaxleft.first;
        else
            answer.first = minMaxRight.first;

        return answer;
    }
    pair<long long, long long> getMinMax(long long arr[], int n)
    {
        // Helper function for recursion
        return minMax(arr, 0, n - 1);
    }
}

class iterativeSolution
{
    struct Pair getMinMax(int arr[], int n)
    {
        struct Pair minmax;
        int i;

        // If array has even number of elements
        // then initialize the first two elements
        // as minimum and maximum
        if (n % 2 == 0)
        {
            if (arr[0] > arr[1])
            {
                minmax.max = arr[0];
                minmax.min = arr[1];
            }
            else
            {
                minmax.min = arr[0];
                minmax.max = arr[1];
            }

            // Set the starting index for loop
            i = 2;
        }

        // If array has odd number of elements
        // then initialize the first element as
        // minimum and maximum
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[0];

            // Set the starting index for loop
            i = 1;
        }

        // In the while loop, pick elements in
        // pair and compare the pair with max
        // and min so far
        while (i < n - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                if (arr[i] > minmax.max)
                    minmax.max = arr[i];

                if (arr[i + 1] < minmax.min)
                    minmax.min = arr[i + 1];
            }
            else
            {
                if (arr[i + 1] > minmax.max)
                    minmax.max = arr[i + 1];

                if (arr[i] < minmax.min)
                    minmax.min = arr[i];
            }

            // Increment the index by 2 as
            // two elements are processed in loop
            i += 2;
        }
        return minmax;
    }

    // Driver code
    int main()
    {
        int arr[] = {1000, 11, 445,
                     1, 330, 3000};
        int arr_size = 6;

        Pair minmax = getMinMax(arr, arr_size);

        cout << "nMinimum element is "
             << minmax.min << endl;
        cout << "nMaximum element is "
             << minmax.max;

        return 0;
    }
}