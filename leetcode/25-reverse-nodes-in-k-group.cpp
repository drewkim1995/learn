// https://leetcode.com/problems/reverse-nodes-in-k-group/

/* My Test Cases:
[1]
2
[1,2,3,4,5,6,7,8,9]
2
[1,2,3,4,5]
2
[1,2,3,4,5]
3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
    private:
        // Returns the last node in the sub-group
        // While adding previousGroups pointer to the head of this sub group
        ListNode* reverse(ListNode *head, ListNode * prevGroup = NULL)
        {
            if (head == NULL)
                return NULL;
            if (head->next == NULL)
            {
                if (prevGroup != NULL)
                    prevGroup->next = head;
                return head;
            }

            ListNode * iter;
            ListNode * tail = head;
            ListNode * prev = NULL;

            while (head != NULL)
            {
                iter = head;
                head = head->next;
                iter->next = prev;
                prev = iter;
            }

            if (prevGroup != NULL)
                prevGroup->next = iter;

            return tail;
        }

    public:
        ListNode* reverseKGroup(ListNode* head, int k)
        {
            int count = 0;
            ListNode * iter = head;
            ListNode * tail = head;
            ListNode * groupA = head;   // Alternating between groups here
            ListNode * groupB = NULL;

            // Indexing
            while (iter != NULL)
            {
                ListNode * prev = iter;
                iter = iter->next;
                count++;

                // Group A turn
                if ((count % (2*k)) == 0)
                {
                    groupA = iter;
                    prev->next = NULL;

                    tail = reverse(groupB, tail);

                    // Reset the tracker
                    count = 0;
                }
                // Group B turn
                else if (count % k == 0)
                {
                    groupB = iter;
                    prev->next = NULL;

                    // Determine if initial/first group
                    if (tail == head)
                    {
                        tail = reverse(groupA);
                        head = prev;
                    }
                    else
                        tail = reverse(groupA, tail);
                }
            }

            // Add any left-out nodes
            if (count % k != 0)
            {
                // if there were more than k elements
                if (tail != head)
                {
                    if (count >= k)
                        tail->next = groupB;
                    else
                        tail->next = groupA;
                }
            }

            return head;
        }
};