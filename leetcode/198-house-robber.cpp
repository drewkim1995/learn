https://leetcode.com/problems/house-robber/
// Test case: [2,7,9,1,1,3]

class Solution {
public:
    int rob(vector<int>& nums) {
        // Padded dynamic programming to prevent edge case of nums.size() == 1
        vector<int> dp(nums.size() + 1, -1);
        return max(houses(dp, nums, 0), houses(dp, nums, 1));
    }

    int houses(vector<int>& dp, vector<int>& nums, int startPos) {
        int retVal = 0;
        int subArraySize = nums.size() - startPos;

        if (dp[startPos] != -1)
            return dp[startPos];

        if (subArraySize == 1)
            retVal = nums[startPos];
        else if(subArraySize == 2)
            retVal = max(nums[startPos], nums[startPos+1]);
        else if (subArraySize >= 3)
            retVal = max(nums[startPos] + houses(dp, nums, startPos+2), houses(dp, nums, startPos+1));

        dp[startPos] = retVal;
        return retVal;
    }
};