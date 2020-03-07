// https://leetcode.com/problems/permutations-ii/

class Solution
{
    private:
        vector<vector<int>> permutations;
        void backtrack(vector<int>& nums, int pos)
        {
            if (pos == nums.size()-1)
            {
                permutations.push_back(nums);
                return;
            }
            for (int i = pos; i < nums.size(); i++)
            {
                if (i < nums.size()-1 && nums[i] == nums[i+1])
                    continue;
                /*
                cout << "[";
                for (auto c : nums)
                    cout << c << " ";
                cout << "], pos = " << pos << endl;*/
                swap(nums[i], nums[pos]);
                backtrack(nums, pos+1);
                swap(nums[i], nums[pos]);
            }
        }
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
            if (nums.size() < 2)
                permutations.push_back(nums);
            else
            {
                sort(nums.begin(), nums.end());
                backtrack(nums, 0);

                sort(permutations.begin(), permutations.end());
                permutations.erase(unique(permutations.begin(), permutations.end()), permutations.end());
            }

            return permutations;
        }
};