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
            // Remove doesn't actually delete elements, just pushes them to the end of container
            vector <int>::iterator pos;
            pos = remove (nums.begin(), nums.end(), 0);
            for(auto i = pos; i != nums.end(); ++i)
                *i = 0;
        }
};