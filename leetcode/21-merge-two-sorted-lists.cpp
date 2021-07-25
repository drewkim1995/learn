// https://leetcode.com/problems/merge-two-sorted-lists/

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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
        {
            ListNode *root = NULL;
            ListNode *current = NULL;

            if (l1 == NULL)
                return l2;
            else if (l2 == NULL)
                return l1;

            while (l1 != NULL && l2 != NULL)
            {
                if (root == NULL)
                {
                    if (l1->val < l2->val)
                    {
                        current = new ListNode(l1->val);
                        l1 = l1->next;
                    }
                    else
                    {
                        current = new ListNode(l2->val);
                        l2 = l2->next;
                    }
                    root = current;
                }
                else
                {
                    if (l1->val < l2->val)
                    {
                        current->next = new ListNode(l1->val);
                        l1 = l1->next;
                    }
                    else
                    {
                        current->next = new ListNode(l2->val);
                        l2 = l2->next;
                    }
                    current = current->next;
                }
            }

            // Merge whatever left over
            if (l1 != NULL)
                current->next = l1;
            else if (l2 != NULL)
                current->next = l2;

            return root;
        }
};