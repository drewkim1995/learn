// https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3286/

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining
the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution
{
    public:
        void moveZeroes(vector<int>& nums)
        {
            int size = nums.size();
            if (size < 2)
                return;

            // Remove Elements
            for (int i = 0; i < nums.size(); ++i)
                if (nums[i] == 0)
                    nums.erase(nums.begin() + i--);

            size = size - nums.size();

            // Add Zeroes
            for (int i = 0; i < size; ++i)
                nums.push_back(0);
        }
};