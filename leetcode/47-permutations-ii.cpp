// https://leetcode.com/problems/permutations-ii/

class Solution
{
    private:
        vector<vector<int>> permutations;
        void recursion(vector<int> nums, int pos)
        {
            if (pos == nums.size()-1)
            {
                permutations.push_back(nums);
                return;
            }

            for (int i = pos; i < nums.size(); i++)
            {
                if (pos != i && nums[pos] == nums[i])
                    continue;
                swap(nums[pos], nums[i]);
                recursion(nums, pos+1);
            }
        }

    public:
        vector<vector<int>> permuteUnique(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            recursion(nums, 0);
            return permutations;
        }
};