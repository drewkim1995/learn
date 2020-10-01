// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution
{
    private:
        vector<int> result;
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
        {
            int size1 = nums1.size();
            int size2 = nums2.size();

            if (size1 == 0 || size2 == 0)
                return result;

            // Sort numbers first
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());

            // Iterators
            int one = 0;
            int two = 0;

            while (one < size1 && two < size2)
            {
                if (nums1[one] == nums2[two])
                {
                    // Store intersection
                    int intersect = nums1[one];
                    result.push_back(intersect);

                    // Find next value that's not the same now.
                    while (++one < size1 && nums1[one] == intersect){}
                    while (++two < size2 && nums2[two] == intersect){}
                }
                else if (nums1[one] > nums2[two])
                    two++;
                else
                    one++;
            }

            return result;
        }
};