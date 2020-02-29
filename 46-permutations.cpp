// https://leetcode.com/problems/permutations/

class Solution
{
    private:
        vector<vector<int>> permutations;
    public:
        vector<vector<int>> permute(vector<int>& nums)
        {
            backtrack(nums, 0);
            return permutations;
        }

        void backtrack(vector<int>& nums, const int pos)
        {
            if (pos == nums.size() - 1)
            {
                permutations.push_back(nums);
                return;
            }

            for (int i = pos; i < nums.size(); i++)
            {
                swap(nums[pos], nums[i]);
                backtrack(nums, pos + 1);
                swap(nums[pos], nums[i]);
            }
        }
};