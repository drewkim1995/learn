// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            int length = 0;
            ListNode * temp = head;
            while (temp != NULL)
            {
                length++;
                temp = temp->next;
            }


            if (n >= length)
            {
                ListNode * old = head->next;
                delete head;
                head = old;
            }
            else
            {
                temp = head;

                // One node before nth from end to delete
                for (int i = 0; i < length-n-1; i++)
                    temp = temp->next;

                ListNode * nth = temp->next;
                temp->next = nth->next;
                delete nth;
            }

            return head;
        }
};