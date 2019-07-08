// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            double ret = 0.0;
            int combinedSize = nums1.size() + nums2.size();
            int start1 = 0;
            int start2 = 0;
            int end1 = nums1.size() - 1;
            int end2 = nums2.size() - 1;

            if (combinedSize == 1)
            {
                if(nums1.size() == 0)
                    ret = nums2[0];
                else
                    ret = nums1[0];
            }

            while (combinedSize > 1)
            {
                int comp1 = 0;
                int comp2 = 0;

                // Get rid of lowest first
                if (start1 < nums1.size())
                {
                    comp1 = nums1[start1];
                }
                else
                {
                    comp1 = nums2[start2++];
                }

                if (start2 < nums2.size())
                {
                    comp2 = nums2[start2];

                    if (comp1 < comp2)
                        start1++;
                    else
                        start2++;
                }
                else
                {
                    comp2 = nums1[++start1];
                }

                cout << "start1 = " << start1 << " | start2 = " << start2 << endl;
                cout << "comp1 = " << comp1 << " | comp2 = " << comp2 << endl;

                if (combinedSize % 2 == 0)
                    ret = (double) (comp1 + comp2) / 2;
                else
                {
                    if (comp1 < comp2)
                        ret = comp2;
                    else
                        ret = comp1;
                }

                // MAYBE FIX THIS PRETEND....
                // Pretend as if we also got rid of highest numbers
                combinedSize -= 2;
            }

            cout << "combined size = " << combinedSize << " | ret = " << ret << endl;

            return ret;
        }
};