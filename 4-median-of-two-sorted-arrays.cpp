// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            double ret = 0.0;

            int start1 = 0;
            int start2 = 0;
            int end1 = nums1.size();
            int end2 = nums2.size();

            int maxLoops = end1+end2;

            // Even
            if (maxLoops % 2 == 0)
                maxLoops = (maxLoops / 2) - 1;
            else
                maxLoops = maxLoops / 2;

            for (int i = 0; i < maxLoops; i++)
            {
                // Remove lowest value
                if (start1 < end1 && start2 < end2)
                {
                    if (nums1[start1] < nums2[start2])
                        start1++;
                    else
                        start2++;
                }
                else if (start1 == end1)
                    start2++;
                else if (start2 == end2)
                    start1++;
            }

            // Odd, only returns single number
            if ((end1+end2) % 2 != 0)
            {
                if (start1 >= end1)
                    ret = nums2[start2];
                else if (start2 >= end2)
                    ret = nums1[start1];
                else
                    ret = nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
            }
            // Even
            else
            {
                if (start1 >= end1)
                    ret = (double) (nums2[start2] + nums2[start2+1]) / 2;
                else if (start2 >= end2)
                    ret = (double) (nums1[start1] + nums1[start1+1]) / 2;
                else
                {
                    // Check for next values of both arrays
                    // e.g. [ 1, 2]
                    //      [-1, 3]
                    int low1 = nums1[start1];
                    int low2 = nums2[start2];

                    if (start1 + 1 < end1 && nums1[start1+1] < low2)
                        low2 = nums1[start1+1];
                    else if (start2 + 1 < end2 && nums2[start2+1] < low1)
                        low1 = nums2[start2+1];

                    ret = (double) (low1 + low2) / 2;
                }
            }

            return ret;
        }
};