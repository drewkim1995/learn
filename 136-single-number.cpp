// https://leetcode.com/problems/single-number/

class Solution
{
    public:
        int singleNumber(vector<int>& nums)
        {
            // Empty or Equal Length Strings invalid
            if (nums.size() % 2 == 0)
                return 0;

            // Sort
            sort(nums.begin(), nums.end());

            // Check every second pair due to sorting
            for (int iter = 1; iter < nums.size(); iter+=2)
            {
                int prev = iter-1;
                if (nums[prev] != nums[iter])
                    return nums[prev];
            }

            // Last number left is the solo
            return nums[nums.size()-1];
        }
};