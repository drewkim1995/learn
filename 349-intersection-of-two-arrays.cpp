// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution
{
    private:
        vector<int> result;
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
        {
            if (nums1.size() == 0 || nums2.size() == 0)
                return result;

            // Sort numbers first
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());

            // Iterators
            int one = 0;
            int two = 0;

            while (one < nums1.size() && two < nums2.size())
            {
                if (nums1[one] == nums2[two])
                {
                    // Store intersection
                    int intersect = nums1[one];
                    result.push_back(intersect);

                    // Find next value that's not the same now.
                    while (++one < nums1.size())
                    {
                        if (nums1[one] != intersect)
                            break;
                    }
                    while (++two < nums2.size())
                    {
                        if (nums2[two] != intersect)
                            break;
                    }
                }
                else if (nums1[one] > nums2[two])
                    two++;
                else
                    one++;
            }

            return result;
        }
};