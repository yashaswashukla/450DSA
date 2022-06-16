/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
*/

/**
 */
class recSolution // O(log n) & S(1)
{
    int first(vector<int> &arr, int start, int end, int x)
    {
        if (end < start)
            return -1;
        int mid = start + (end - start) / 2;

        if ((mid == 0 || x > arr[mid - 1]) && x == arr[mid])
            return mid;
        else if (x > arr[mid])
            return first(arr, mid + 1, end, x);
        else
            return first(arr, start, mid - 1, x);
    }

    int last(vector<int> &arr, int start, int end, int x)
    {
        if (end < start)
            return -1;
        int mid = start + (end - start) / 2;

        if ((mid == arr.size() - 1 || x < arr[mid + 1]) && x == arr[mid])
            return mid;
        else if (x < arr[mid])
            return last(arr, start, mid - 1, x);
        else
            return last(arr, mid + 1, end, x);
    }
    vector<int> find(int arr[], int n, int x)
    {
        vector<int> answer;
        answer.push_back(first(arr, 0, n - 1, x));
        if (answer[0] == -1)
            return answer;

        answer.push_back(last(arr, 0, n - 1, x));
        return answer;
    }
};

class iterSolution
{
    vector<int> find(int arr[], int n, int x)
    {
        int fi = -1, li = -1;
        int low = 0, high = n - 1;

        // Finding the first Occurance of the element

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x)
            {
                high = mid - 1;
                fi = mid;
            }
            else if (arr[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        // Finding the Last Occurance of the element

        low = 0;
        high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x)
            {
                li = mid;
                low = mid + 1;
            }
            else if (arr[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        vector<int> ans;
        ans.push_back(fi);
        ans.push_back(li);

        return ans;
    }
}