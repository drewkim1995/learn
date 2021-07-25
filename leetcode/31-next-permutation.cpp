// https://leetcode.com/problems/next-permutation/solution/

class Solution
{
    public:
        // For any sequence that is in desc order, no next larger permuation is possible.
        void nextPermutation(vector<int>& nums)
        {
            int size = nums.size();
            int shiftIndex;
            int larger;

            // shiftIndex is when the descending order is broken
            for (shiftIndex = size - 2; shiftIndex >= 0; shiftIndex--)
            {
                if (nums[shiftIndex] < nums[shiftIndex + 1])
                    break;
            }

            // No rearrangements due to descending order, default to smallest order
            if (shiftIndex < 0)
                reverse(nums.begin(), nums.end());
            else
            {
                // Find a number larger than at shiftIndex to replace with
                for (larger = size - 1; larger > shiftIndex; larger--)
                {
                    if (nums[larger] > nums[shiftIndex])
                        break;
                }
                swap(nums[shiftIndex], nums[larger]);

                // Smallest permutation formed by sorting numbers to the right in ascending
                reverse(nums.begin() + shiftIndex + 1, nums.end());
            }
        }
};