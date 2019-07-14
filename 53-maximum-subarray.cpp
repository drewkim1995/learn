// https://leetcode.com/problems/maximum-subarray/

class Solution
{
    public:
        int maxSubArray(vector<int>& nums)
        {
            int highest = 0;
            int sum = 0;

            if (nums.size() > 0)
            {
                highest = nums[0];
                for (int i = 0; i < nums.size(); i++)
                {
                    sum += nums[i];

                    if (highest < sum)
                        highest = sum;
                    if (sum < 0)
                        sum = 0;
                }

            }

            return highest;
        }
};