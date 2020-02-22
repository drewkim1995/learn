// https://leetcode.com/problems/first-missing-positive/

class Solution
{
    public:
        int firstMissingPositive(vector<int>& nums)
        {
            int small = 1;
            sort(nums.begin(), nums.end());

            for (auto it : nums)
            {
                if (it == small)
                    small++;
            }

            return small;
        }
};