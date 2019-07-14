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

            int remaining = end1+end2;
            int maxLoop = (remaining / 2) - 1;

            while (remaining > 1)
            {
                // Remove lowest value
                if (start1 < end1 && start2 < end2)
                {
                    if (nums1[start1] < nums2[start2])
                    {
                        if (remaining % 2 == 0)
                            ret = (nums1[start1] + nums2[start2]) / 2;
                        else
                            ret = nums2[start2];
                        start1++;
                    }
                    else
                    {
                        if (remaining % 2 == 0)
                            ret = (nums1[start1] + nums2[start2]) / 2;
                        else
                            ret = nums1[start1];
                        start2++;
                    }
                }
                else if (start1 >= end1)
                {
                    start2++;
                    ret = nums2[start2];
                    /*
                    if (start2 < end2)
                        ret = (nums2[start2-1] + nums2[start2]) / 2;
                    else
                    {
                        ret = nums2[start2-1];
                        break;
                    }*/
                }
                else if (start2 >= end2)
                {
                    start1++;
                    ret = nums1[start1];
                    /*
                    if (start1 < end1)
                        ret = (nums1[start1-1] + nums1[start1]) / 2;
                    else
                    {
                        ret = nums1[start1-1];
                        break;
                    }*/
                }
                cout << remaining << " loop " << start1 << "|" << end1 << " | " << start2 << "|" << end2 << endl;
                remaining -= 2;
            }

            cout << "start1 = " << start1 << " | end1 = " << end1 << endl;
            cout << "start2 = " << start2 << " | end2 = " << end2 << endl << endl;

            if ((end1+end2) % 2 != 0)
            {
                // Odd
                if (start1 >= end1)
                    ret = nums2[start2];
                else if (start2 >= end2)
                    ret = nums1[start1];
                else
                    ret = nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
            }
            else
            {
                cout << "hello ";
            cout << "start1 = " << start1 << " | end1 = " << end1 << endl;
            cout << "start2 = " << start2 << " | end2 = " << end2 << endl << endl;
                // Even
                if (start1 >= end1)
                {
                    if (start2 == 0)
                        ret = (double) (nums1[end1-1] + nums2[start2]) / 2;
                    else
                        ret = (double) (nums2[start2-1] + nums2[start2]) / 2;
                }
                else if (start2 >= end2)
                {
                    if (start1 == 0)
                        ret = (double) (nums2[end2-1] + nums1[start1]) / 2;
                    else
                        ret = (double) (nums1[start1-1] + nums1[start1]) / 2;
                }
                else
                    ret = (double) (nums1[start1] + nums2[start2]) / 2;

            } // If I stop 1 loop earlier, just add the results of [start1] and [start2]?

            return ret;
        }
};