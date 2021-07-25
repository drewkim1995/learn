//https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
        ListNode* deleteDuplicates(ListNode* head)
        {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode * current = head->next;
            ListNode * previous = head;

            while(current != NULL)
            {
                if (previous->val == current->val)
                {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                }
                else
                {
                    previous = current;
                    current = current->next;
                }
            }

            return head;
        }
};