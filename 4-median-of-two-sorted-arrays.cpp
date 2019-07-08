// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            vector<int> * m;
            vector<int> * n;

            double ret = 0.0;
            int combinedSize = nums1.size() + nums2.size();

            if (nums1[0] <= nums2[0])
            {
                m = &nums1;
                n = &nums2;
            }
            else
            {
                m = &nums2;
                n = &nums1;
            }

            // Even
            if (combinedSize % 2 == 0)
            {
                int index1 = combinedSize / 2;
                int index2 = index1 + 1;
                cout << index1 << " " << index2 << endl;

                if (index1 < m->size())
                {
                    ret = m->at(index1);

                    if (index2 < m->size())
                        ret = (ret + m->at(index2)) / 2;
                    else
                        ret = (ret + n->at(index2 - m->size())) / 2;
                }
                else
                {
                    index1 -= m->size();
                    index2 -= m->size();
                    ret = (n->at(index1) + n->at(index2)) / 2;
                }

            }
            // Odd
            else
            {
                // Get the 'middle'
                int index = (combinedSize % 2) + 1;
                cout << index << endl;
                if (index < m->size())
                    ret = m->at(index);
                else
                    ret = n->at(index - m->size());
            }

            return ret;
        }
};