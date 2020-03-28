/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://leetcode.com/problems/rotate-list/


class Solution
{
    private:
        int getLength(ListNode * head)
        {
            int count = 0;
            ListNode * prev = NULL;
            ListNode * iter = head;

            while (iter != NULL)
            {
                ++count;
                prev = iter;
                iter = iter->next;
            }

            // Converting the link list into circular list
            if (count > 0)
                prev->next = head;

            return count;
        }

    public:
        ListNode* rotateRight(ListNode* head, int k)
        {
            ListNode * origHead = head;

            // Find how many spaces to rotateLeft
            int length = getLength(head);
            if (length == 0)
                return head;
            k = length - (k % length);

            // Seek to position before new head
            while(k - 1 > 0)
            {
                head = head->next;
                k--;
            }

            // Set the position before new head as tail
            ListNode * temp = head->next;
            head->next = NULL;
            head = temp;

            return head;
        }
};