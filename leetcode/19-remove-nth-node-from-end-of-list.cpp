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
            ListNode *adv = head;

            for (int i = 0; i < n; i++)
                adv = adv->next;

            ListNode *nth = head;

            // Delete root
            if (adv == NULL)
            {
                nth = head->next;
                delete head;
                head = nth;
            }
            else
            {
                // Stops 1 before target
                while (adv->next != NULL)
                {
                    adv = adv->next;
                    nth = nth->next;
                }

                ListNode *tmp = nth->next;
                nth->next = tmp->next;
                delete tmp;
            }

            return head;
        }
};