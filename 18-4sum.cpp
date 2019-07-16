// https://leetcode.com/problems/4sum/

class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            if (nums.empty())
                return {};

            int size = nums.size();
            vector<vector<int>> ret;

            // Sort first
            sort(nums.begin(), nums.end());

            // First value
            for (int i = 0; i < size - 3; i++)
            {
                // Handle worst case scenarios
                // Avoid duplicates
                if (i > 0 && nums[i] == nums[i-1])
                    continue;
                // No solution
                if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                    break;
                // 'i' is too small
                if (nums[i] + nums[size-3] + nums[size-2] + nums[size-1] < target)
                    continue;

                // Second value
                for (int j = i + 1; j < size - 2; j++)
                {
                    // Avoid duplicates part 2
                    if (j > i + 1 && nums[j] == nums[j-1])
                        continue;

                    int k = j + 1;      // Third value
                    int l = size - 1;   // Fourth value

                    while (k < l)
                    {
                        // Remember we sorted the input!
                        int sum = nums[i] + nums[j] + nums[k] + nums[l];

                        // Get a number smaller than current l
                        if (sum > target)
                            l--;
                        // Get a number larger than current k
                        else if (sum < target)
                            k++;
                        // Match
                        else
                        {
                            ret.push_back({nums[i], nums[j], nums[k++], nums[l--]});

                            // Avoid duplicates to k
                            while (nums[k] == nums[k-1] && k < l)
                                k++;

                            // Avoid duplicates to l
                            while (nums[l] == nums[l+1] && k < l)
                                l--;
                        }
                    }
                }
            }

            return ret;
        }
};