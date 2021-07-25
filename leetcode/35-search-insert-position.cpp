// https://leetcode.com/problems/search-insert-position/

class Solution
{
    public:
        int searchInsert(vector<int>& nums, int target)
        {
            int index = 0;

            if (!nums.empty())
            {
                for (int i = 0; i < nums.size(); i++)
                {
                    if (nums[i] == target || nums[i] > target)
                        return i;
                    index = i+1; //if (nums[i] < target)
                }
            }

            return index;
        }
};