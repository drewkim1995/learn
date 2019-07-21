// https://leetcode.com/problems/merge-k-sorted-lists/

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
        ListNode* mergeKLists(vector<ListNode*>& lists)
        {
            // Test for fringe e.g. empty
            if (lists.empty())
                return NULL;

            ListNode * root = lists[0];

            for (int i = 1; i < lists.size(); i++)
            {
                ListNode * curr = root;
                ListNode * prev = root;
                ListNode * iter = lists[i];

                while (curr != NULL && iter != NULL)
                {
                    /*
                    cout << "prev = " << prev->val << endl;
                    cout << "curr = " << curr->val << endl;
                    cout << "iter = " << iter->val << endl << endl;*/
                    // Compare Values
                    if (iter->val < curr->val)
                    {
                        if (prev == curr)
                        {
                            root = iter;
                            iter = iter->next;

                            prev = root;
                            prev->next = curr;

                        }
                        else
                        {
                            prev->next = iter;
                            iter = iter->next;
                            prev = prev->next;
                            prev->next = curr;
                        }
                    }
                    else
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                }

                if (curr == NULL && iter != NULL)
                {
                    if (prev != NULL)
                        prev->next = iter;
                    else
                        root = iter;
                }

            }


            return root;
        }
};