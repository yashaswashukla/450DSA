/*
LeetCode: https://leetcode.com/problems/merge-k-sorted-lists/
GFG: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
*/

/**
 * As all the list are sorted. So, we will compare the first values of all the list and whichever has the
 * lowest value, We will insert it in our answer list.
 * Now from which ever list we have selected this node will move the pointer to it's next node
 * Similarly, we will compare the value again & over again and which ever is the smallest we put that in result list.
 *
 */
class naiveSolution // O(N*K) & S(N)
{
    Node *mergeKList(Node *list[], int k)
    {
        // Base Case
        if (list == nullptr || k == 0)
            return nullptr;

        // Result list
        Node *head = new Node(0);
        Node *temp = head;

        while (true)
        {
            int p = 0; // Storing the lowest value, initially pointing to the head node of the first list
            for (int i = 0; i < k; i++)
            {
                // Updating the lowest value in the p
                if (list[p] == nullptr || (list[i] != nullptr && list[p]->data > list[i]->data))
                    p = i;
            }

            // Last case when list[p] does not point to any node, means there is no element left in the list
            // We end the loop

            if (list[p] == nullptr)
                break;

            // Updating the answer list
            temp->next = list[p];
            temp = temp->next;
            // Correcting the pointers of the list[p] as the first element was included in the answer we will now point to the
            // second node of the list
            list[p] = list[p]->next;
        }
        return head->next;
    }
};

/**
 *
 *
 */

class divideNConquer // O(N*logK) & S(K)
{
    Node *mergeKList(Node *list[], int k)
    {
        if (list == nullptr || k == 0)
            return nullptr;

        // Creating a helper function to start our recursion

        return getMid(list, 0, k - 1);
    }
    Node *getMid(Node *list[], int start, int end)
    {
        // Base case if only 1 list is left in the Array then we return it
        if (start == end)
            return list[start];

        // Finding the middle point of the list
        int mid = start + (end - start) / 2;

        // Getting the left list and right list or dividing the list in sub parts
        Node *left = getMid(list, start, mid);
        Node *right = getMid(list, mid + 1, end);

        // Merging them
        return merge(left, right);
    }

    Node *merge(Node *left, Node *right)
    {
        // Creating a answer list and a dummy pointer to add the elements to the list
        Node *answer = new Node(0);
        Node *temp = answer;

        while (left || right)
        {
            if (!left)
            {
                temp->next = right;
                right = right->next;
            }
            else if (!right)
            {
                temp->next = left;
                left = left->next;
            }
            else if (left->data < right->data)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }

            // Moving the dummy pointer to the next node
            temp = temp->next;
        }

        return answer->next;
    }
}