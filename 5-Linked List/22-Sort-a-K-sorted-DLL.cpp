/*
LeetCode:
GFG: https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/
*/

/**
 */
class insertionSortSolution // O(n*k) & S(1)
{
    struct node *sortAKSortedDLL(struct node *head, int k)
    {
        // If we don't have a head or only a single element
        if (!head || !head->next)
            return head;

        // Starting the insertion sort on the linked list;
        // As we have to compare the elements to the element before them
        // So, starting with head->next
        for (Node *i = head->next; i != nullptr; i = i->next)
        {
            // Node we will compare to
            Node *j = i;

            // Comparing the node to it's previous node and checking if the data of the previous node is smaller than
            //  the current node then we will swap them
            while (j->prev && j->data < j->prev->data)
            {
                // Swaping the j and j->prev nodes

                // Temp to store the prev to prev of j to modify the link
                Node *temp = j->prev->prev;
                // Temp2 to store j->prev
                Node *temp2 = j->prev;
                // Temp3 to store j->next;
                Node *temp3 = j->next;

                /**
                 * Links we have to modify to swap j and j->prev
                 * Links of j:
                 * j->next will be j->prev as swapping them
                 * j->prev will be j->prev->prev
                 * Links of j->prev:
                 * j->prev->next=j->next;
                 * j->prev->prev=j;
                 *
                 * also if j->prev->prev is not null then we will have to change it's next
                 * Similarly if j->next is not null then we will have to change it's prev
                 */

                j->prev->next = temp3;
                j->prev->prev = j;
                j->prev = temp;
                j->next = temp2;

                if (temp)
                    temp->next = j;
                if (temp3)
                    temp3->prev = temp2;
            }

            // After putting the j to it's correct position we will check if it is the first element of the list or not
            // If it is then we have to change the head to point at j
            if (j->prev == nullptr)
                head = j;
        }

        return head;
    }
}